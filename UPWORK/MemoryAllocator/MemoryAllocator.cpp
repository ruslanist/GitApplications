/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <iostream>
#include <vector>
#include "MemoryAllocator.h"

#include "MemoryAllocator.h"

using namespace std;

void MemoryAllocator::set_uint32(uint32_t val, uint32_t addr, vector<uint8_t> & mem) {
    mem[addr++] = (uint8_t)(val >> 24);
    mem[addr++] = (uint8_t)(val >> 16);
    mem[addr++] = (uint8_t)(val >> 8);
    mem[addr++] = (uint8_t) val;
}

uint32_t MemoryAllocator::get_uint32(uint32_t addr, const vector<uint8_t> & mem) {
    uint32_t ret_val = 0;
    ret_val |= ((uint32_t)mem[addr++]) << 24;
    ret_val |= ((uint32_t)mem[addr++]) << 16;
    ret_val |= ((uint32_t)mem[addr++]) << 8;
    ret_val |= ((uint32_t)mem[addr++]);

    return ret_val;
}

bool MemoryAllocator::FreePageFrames(uint32_t count, vector<uint32_t> &page_frames) {
    if(page_frames.size() < count)
        return false;

    if(count > (get_page_frames_total() - get_page_frames_free()))
        return false;

    uint32_t free_head = get_free_list_head();

    for(uint32_t i = 0; i < count; i++) {
        uint32_t page_addr = page_frames.back();
        page_frames.pop_back();

        set_uint32(free_head, page_addr, memory);
        free_head = page_addr;
    }

    set_free_list_head(free_head);

    uint32_t old_free_num = get_page_frames_free();
    set_page_frames_free(count + old_free_num);

    return true;
}

bool MemoryAllocator::AllocatePageFrames(uint32_t count, vector<uint32_t> &page_frames) {
    uint32_t free_pages_num = get_page_frames_free();

    if(free_pages_num < count)
        return false;

    for(uint32_t i = 0; i < count; i++) {
        uint32_t free_head = get_free_list_head();
        if(free_head == 0xFFFFFFFF)
            return false;

        page_frames.push_back(free_head);
        uint32_t next_free_head = get_uint32(free_head, memory);
        set_free_list_head(next_free_head);

        std::fill(memory.begin() + free_head, memory.begin() + free_head + page_frame_size, 0);
    }

    set_page_frames_free(free_pages_num - count);

    return true;
}

void MemoryAllocator::set_page_frames_total(uint32_t page_frames_total) {
    set_uint32(page_frames_total, page_frames_total_addr, memory);
}

void MemoryAllocator::set_page_frames_free(uint32_t page_frames_free) {
    set_uint32(page_frames_free, page_frames_free_addr, memory);
}

void MemoryAllocator::set_free_list_head(uint32_t list_head) {
    set_uint32(list_head, free_list_head_addr, memory);
}

uint32_t MemoryAllocator::get_free_list_head() const {
    return get_uint32(free_list_head_addr, memory);
}

uint32_t MemoryAllocator::get_page_frames_free() const {
    return get_uint32(page_frames_free_addr, memory);
}

uint32_t MemoryAllocator::get_page_frames_total() const {
    return get_uint32(page_frames_total_addr, memory);
}

void MemoryAllocator::get_free_page_list(vector<uint32_t>& out_list) const {
    uint32_t free_head = get_free_list_head();
    while(free_head != 0xFFFFFFFF) {
        out_list.push_back(free_head);
        free_head = get_uint32(free_head, memory);
    }
}

MemoryAllocator::MemoryAllocator(uint32_t page_frames_num) {
    memory.resize(page_frames_num * page_frame_size);

    set_page_frames_total(page_frames_num);
    set_page_frames_free(page_frames_num - 1);

    for(size_t page_addr = page_frame_size; page_addr < memory.size(); page_addr += page_frame_size) {
        uint32_t next_page_addr = page_addr + page_frame_size;
        if(next_page_addr == memory.size()) {
            set_uint32(0xFFFFFFFF, page_addr, memory);
        } else {
            set_uint32(next_page_addr, page_addr, memory);
        }
    }

    set_free_list_head(page_frame_size);
}



       
