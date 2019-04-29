#include <iostream>
#include "MemoryAllocator.h"
#include <fstream>
#include <sstream>
#include <string>
#include <inttypes.h>

using std::cout;
using std::endl;

const uint32_t PRINT_FREE_PAGES_LIST = 2;
const uint32_t ALLOCATE_PAGES = 1;
const uint32_t DEALLOCATE_PAGES = 0;

int main(int argc, char** argv) {
    std::ifstream infile(argv[1]);
    infile >> std::hex;
    cout << std::hex;

    uint32_t page_num = 0;
    if( !(infile >> page_num) ) {
        cout << "Fail to parse page number" << endl;
        return -1;
    }

    cout << "#" << page_num << endl;

    MemoryAllocator allocator(page_num);
    std::vector<uint32_t> allocated_page_frames;

    while(true) {
        uint32_t next_cmd = 0;

        if( !(infile >> next_cmd) ) {
            if (infile.eof()) {
                return 0;
            }

            cout << "Fail to parse next commands" << endl;
            return -1;
        }

        switch(next_cmd) {
            case PRINT_FREE_PAGES_LIST: {
                cout << "#" << next_cmd << endl;

                std::vector<uint32_t> out_list;
                allocator.get_free_page_list(out_list);
                for(int i = 0; i < out_list.size(); i++) {
                    cout << " " << out_list[i];
                }
                cout << endl;
            } break;
            case ALLOCATE_PAGES:
            case DEALLOCATE_PAGES: {
                uint32_t page_count;
                if( !(infile >> page_count) ) {
                    cout << "Fail to parse page_count for command " << next_cmd << endl;
                    return -1;
                }

                cout << "#" << next_cmd << " " << page_count << endl;

                if(next_cmd == ALLOCATE_PAGES) {
                    bool ret_val = allocator.AllocatePageFrames(page_count, allocated_page_frames);
                    cout << " " << (ret_val ? "T" : "F") << " " << allocator.get_page_frames_free() << endl;
                } else {
                    bool ret_val = allocator.FreePageFrames(page_count, allocated_page_frames);
                    cout << " " << (ret_val ? "T" : "F") << " " << allocator.get_page_frames_free() << endl;
                }
            } break;
            default: {
                cout << "Bad command " << next_cmd << endl;
                return -1;
            } break;
        }
    }


    return 0;
}

