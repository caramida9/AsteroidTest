#ifndef ASSETMANAGER_H_INCLUDED
#define ASSETMANAGER_H_INCLUDED

#include <string>

template <typename ASSET>
class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	ASSET *Create(const std::string &assetId,
		const typename ASSET::CreateParams *params);
	ASSET *Get(const std::string &assetId) const;
	void Destroy(const std::string &assetId);

private:
	AssetManager(const AssetManager &);
	void operator=(const AssetManager &);

};


#endif // ASSETMANAGER_H_INCLUDED
