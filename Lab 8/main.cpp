#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

map<string, int> split(string s, string delimiters) 
{
	map<string, int> words;
	int pos = 0;
	string word;
	while (s.find_first_of(delimiters) != string::npos)
	{
		pos = s.find_first_of(delimiters);
		if (pos != 0) {
			word = s.substr(0, pos);
			for (char& ch : word)
				if (ch < 97) ch += 32;
			words[word]++;
		}
		s.erase(0, pos + 1);
	}
	return words;
}

class Compare {
public:
	bool operator() (pair<string, int> a, pair<string, int> b)
	{
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second < b.second;
	}
};


int main()
{
	string s;
	ifstream file("input.txt");
	if (!file)
	{
		printf("eroare la deschiderea fisierului");
		return 0;
	}
	
	if (!getline(file, s))
	{
		printf("eroare la citirea din fisier");
		return 0;
	}
	string delimiters = " ,.!?";
	map<string, int> map = split(s, delimiters);
	priority_queue< pair<string, int>, vector<pair<string, int>>, Compare> queue;
	for (auto w : map)
		queue.push(w);
	while (!queue.empty())
	{
		pair<string, int> w = queue.top();
		printf("%s => %d\n", w.first.c_str(), w.second);
		queue.pop();
	}
}
