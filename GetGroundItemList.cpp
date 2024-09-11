
#define __uint64 uint64_t


typedef struct SGroundItemInstance
{
	void* Instance;
	uint32_t dwVirtualNumber;
	D3DVECTOR v3EndPosition;

	D3DVECTOR v3RotationAxis;
	D3DXQUATERNION qEnd;
	D3DVECTOR v3Center;
	void* ThingInstance;
	char pad_002c8[0x198];
	uint64_t dwStartTime;
	uint64_t dwEndTime;

	uint32_t eDropSoundType;

	uint32_t dwEffectInstanceIndex;

	std::string stOwnership;
} TGroundItemInstance;


std::map<uint32_t, TGroundItemInstance*> GetGroundItemList()
{
	std::map<uint32_t, TGroundItemInstance*> itemList;
	std::string player_name = GetName(PlayerNEW_GetMainActorPtr());

	auto Myhead = *(__uint64**)(GameBase::g_CPythonItem + 0x8);
	auto _Left = (__uint64*)*Myhead;
	if ((__uint64*)*Myhead != Myhead)
	{
		do
		{
			if (*reinterpret_cast<uint32_t*>(_Left[5] /* Value */ + 0x8 /* dwVirtualNumber offset */) != 435224356 /* dwVirtualNumber end */)
			{
				auto ItemID = *reinterpret_cast<uint32_t*>(_Left + 0x8); /* Key */
				auto groundItem = reinterpret_cast<TGroundItemInstance*>(_Left[5]); /* Value */
				std::string ownerShip = "";
				try
				{
					ownerShip = static_cast<std::string>(reinterpret_cast<char*>(groundItem) + 0x208);
				}
				catch (...)
				{
				}
				if (ownerShip == "" || ownerShip == player_name)
				{
					itemList.insert(std::make_pair(ItemID, groundItem));
				}
			}
			auto Right = (__uint64**)_Left[2];
			if (*((BYTE*)Right + 0x19 /* _Isnil */))
			{
				uint64_t i;
				for (i = _Left[1] /* _Parent */; !*(BYTE*)(i + 0x19) /* _Isnil */; i = *(uint64_t*)(i + 0x8) /* _Parent */)
				{
					if (_Left != *(__uint64**)(i + 0x10) /* _Right */)
						break;
					_Left = (__uint64*)i;
				}
				_Left = (__uint64*)i;
			}
			else
			{
				auto v8 = *Right;
				for (_Left = (__uint64*)_Left[2] /* _Right */; !*((BYTE*)v8 + 0x19) /* _Isnil */; v8 = (__uint64*)*v8)
					_Left = v8;
			}
		} while (_Left != *(__uint64**)(GameBase::g_CPythonItem + 0x8));
	}

	return itemList;
}