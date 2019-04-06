#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename InputIt, typename OutputIt>
void scatter(InputIt first, InputIt last, OutputIt &d_first) {

    d_first.assign(first, last);

}

int main()
{

    vector<int> myVec{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> myVec1;

    scatter(myVec.begin(), myVec.end(), myVec1);

    for(int i =0; i < myVec1.size(); i++) {

        cout << myVec1[i] << endl;
    }


    cout << "Hello World!" << endl;

    return 0;
}
