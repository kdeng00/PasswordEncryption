#ifndef KEY_H_
#define KEY_H_

#include<vector>
#include"FolderStructure.h"
#include"GenerateDate.h"

using std::string;
using std::vector;

template<typename S = string>
class Key
{
	S filename;
	const S keyDirectory{FolderStructure::keyDirectory};
	vector<S> keys;
public:
	Key();
	explicit Key(const S&);
	~Key() = default;

	void keysInit(vector<S>&);
	void setupFilename(const S&);
	void generatedFilename();	
	S path() const;
	S retrieveFilename() const;
	vector<S> retrieveKeys() const;
};

template<typename S>
Key<S>::Key()
{
	generatedFilename();
}
template<typename S>
Key<S>::Key(const S& filename) : filename(filename)
{
}

template<typename S>
void Key<S>::keysInit(vector<S>& keyFromElseWhere)
{
	keys.swap(keyFromElseWhere);
}
template<typename S>
void Key<S>::setupFilename(const S& filename) { this->filename.assign(filename); }
template<typename S>
void Key<S>::generatedFilename()
{
	GenerateDate<S, int> gd;
	filename.assign(gd.retrieveDateString());
	for (auto index=0; index!=8; ++index)
	{
		if (index==0) filename.append("_");
		else 
		{
			auto randomInteger = rand()%10;
			filename.append(std::to_string(randomInteger));
		}	
	}
	filename.append(".txt");
}
template<typename S>
S Key<S>::retrieveFilename() const { return filename; }
template<typename S>
S Key<S>::path() const { return keyDirectory + filename; }
template<typename S>
vector<S> Key<S>::retrieveKeys() const { return keys; }
#endif
