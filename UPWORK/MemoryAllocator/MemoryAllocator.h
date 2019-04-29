#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H
#include <vector>
#include <inttypes.h>

using namespace std;

class MemoryAllocator {
    
public:
    MemoryAllocator(uint32_t page_frames_num);

    bool AllocatePageFrames(uint32_t count, vector<uint32_t> &page_frames);
    bool FreePageFrames(uint32_t count, vector<uint32_t> &page_frames);
    uint32_t get_page_frames_free() const;
    void get_free_page_list(vector<uint32_t> &out_list) const;

private:
    void set_page_frames_total(uint32_t page_frames_total);
    void set_page_frames_free(uint32_t page_frames_free);
    void set_free_list_head(uint32_t list_head);

    uint32_t get_free_list_head() const;
    uint32_t get_page_frames_total() const;

    static void set_uint32(uint32_t val, uint32_t addr, vector<uint8_t> & mem);
    static uint32_t get_uint32(uint32_t addr, const vector<uint8_t> & mem);

    static const uint32_t page_frame_size = 65536;
    static const uint32_t page_frames_total_addr = 0;
    static const uint32_t page_frames_free_addr = 4;
    static const uint32_t free_list_head_addr = 8;


    vector<uint8_t> memory;
};


#endif /* MEMORYALLOCATOR_H */

