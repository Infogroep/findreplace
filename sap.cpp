#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string to_string(int i)
{	stringstream ss;
	string line;
	ss << i;
	getline(ss, line);
	return line;
}


void find_replace(string&  inputfile, string& csvfile )//andere para to replace
{	ifstream in(csvfile.c_str()); //dit is de csv file

	string name;
	string csw;
	string line;
	string csvline;
	stringstream csv;

	getline(in, csvline);
	csv << csvline;
	vector<string> firstline;
	while(getline(csv, csvline, ',')){
		firstline.push_back(csvline);
	}

	unsigned int cnt = 0;

	while (getline(in, csvline))
	{	vector<string> vect;
		stringstream csv2;
		csv2 << csvline;

		while(getline(csv2, csvline, ',')){
		vect.push_back(csvline);
		}

		for(int i = 0; i<vect.size(); i++){
			cout<< vect[i]<<'\n';
		}

		ofstream out(vect[0] + string(".tex"));
		ifstream input(inputfile.c_str()); //dit is de input file

		while(getline(input, line)){

				while(cnt < firstline.size()){
					size_t pos = line.find(firstline[cnt]);

					while(pos != string::npos){
						line.replace(pos, firstline[cnt].length(), vect[cnt]);
						pos = line.find(firstline[cnt], pos+1);
					}
					cnt++;
				}
				cnt = 0;
				out << line << '\n';
			}
			input.close();
	}
cout<<"done";
}


vector <vector <string> > data;
ifstream infile( "test.txt" );


int main ()
{	string input("bedrijvendag.tex");
	string csv("csv.csv");
	find_replace(input, csv);
	return 0;
}
