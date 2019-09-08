// Search for std::map<DWORD, CLevelItemGroup*> m_map_pkLevelItemGroup; 
// add after

#ifdef MOB_DROP_ITEM_RENEWAL
		std::map<DWORD, CMapIndexItemGroup*> m_map_pkMapIndexItemGroup;
#endif

// Search for class CLevelItemGroup 
// after this class add

#ifdef MOB_DROP_ITEM_RENEWAL
class CMapIndexItemGroup
{
	struct SMapIndexItemGroup
	{
		DWORD dwVNum;
		DWORD dwPct;
		int iCount;

		SMapIndexItemGroup(DWORD dwVnum, DWORD dwPct, int iCount)
			: dwVNum(dwVnum), dwPct(dwPct), iCount(iCount)
		{ }
	};

	private :
		DWORD m_dwMapIndex;
		std::string m_stName;
		std::vector<SMapIndexItemGroup> m_vec_items;

	public :
		CMapIndexItemGroup(DWORD dwMapIndex)
			: m_dwMapIndex(dwMapIndex)
		{}

		DWORD GetMapIndex() { return m_dwMapIndex; }

		void AddItem(DWORD dwItemVnum, DWORD dwPct, int iCount)
		{
			m_vec_items.push_back(SMapIndexItemGroup(dwItemVnum, dwPct, iCount));
		}

		const std::vector<SMapIndexItemGroup> & GetVector()
		{
			return m_vec_items;
		}
};
#endif