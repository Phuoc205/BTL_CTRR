#include "bellman.h"
#include "tsm.h"

int random(){
    srand(time(0));
    static int temp = rand();
    int randomValue = (temp*temp*temp-3*temp*temp+8*temp-92) % 100;
    temp++;
    if(randomValue<0) randomValue = -randomValue;
    return randomValue;
}

class Test{
private:
    int G[20][20];
    int v;
    int current_value[20];
    int previous_array[20];
public:
    Test(int v);
    Test(string linkfile);
    void DisplayMatrix();
    void TestBF( char init );
    void TestBF_PATH();
    void TestTraveling();
};

Test :: Test(string linkfile){
    ifstream input(linkfile);
    string line;
    int i = 0;
    int count = 0;
	while(getline(input,line) && i<v) {
        if(i==0){
            for(int i=0; i<line.length(); i++){
                if(line[i] == ' ') count++;
            }
            this->v = ++count;
        }
		stringstream ss(line);
        for (int j = 0; j < v; j++) {
            ss >> G[i][j];
        }
        i++;
	}
    input.close();
}

Test :: Test(int v) {
    this->v = v;
    for(int i=0 ; i<v ; i++) {
        for(int j=0 ; j<v ; j++) {
            if(i==j) G[i][j] = 0;
            else G[i][j] = random();
        }
    }
}

void Test :: DisplayMatrix() {
    for(int i=0 ; i<v ; i++) {
        for(int j=0 ; j<v ; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void Test :: TestBF( char init ){
    fill(current_value, current_value + v, -1);
    fill(previous_array, previous_array + v, -1);
    cout << "Star vertex " << char(init) << ":" << endl;
    for (int i = 0 ; i < v ; i++){
        BF( G , v , init , current_value , previous_array );
        cout << "step" << i << ":" << endl;
        for(int j = 0; j < v ; j++){
            cout << current_value[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < v ; j++){
            cout << previous_array[j] << " ";
        }
        cout << endl;
    }
}

void Test :: TestBF_PATH(){
    for(int i = 0 ; i < v ; i++) {
        for(int j = 0 ; j < v ; j++) {
            cout << char(i+'A') << " to " << char(j+'A') << ": " ;
            cout << BF_Path( G , v , char(i+'A') , char(j+'A') ) << endl;
        }
    }
}

void Test :: TestTraveling(){
    for(int i = 0 ; i < v ; i++) {
        cout << "Traveling with start vertex is " << char(i+'A') << ": " << endl;
        cout << "Total distance: " << getresult(G , v , char(i+'A')) << endl;
        cout << "Path: ";
        cout << Traveling( G ,v ,char(i+'A')) << endl << endl;
    }
}

int main(){

    /*
    You have two way for test this assignment. The first one, you can get matrix from file by constructor TestMap(string linkfile, int v),
    in there, linkfile is a name of file, v is the number of vertex. The second one, if you don't have any file, you can use this. This is
    a constructor in which we inport each element on a random number but you must transmiss the number of vertex Testmap(int v). And then,
    you can check matrix with the function DisplayMatrix(). Use each function appropriately for testing. Thank you !!!

    TestBF( char init ) in which init is the start vertex
    TestBF_PATH()
    TestTraveling()

    Name of student: Nguyen Tan Phuoc; Id: 2312776
    */

    Test test("BF2.txt");
    // test.DisplayMatrix();
    test.TestBF('A');
    // test.TestBF_PATH();
    // test.TestTraveling();
    return 0;
}

