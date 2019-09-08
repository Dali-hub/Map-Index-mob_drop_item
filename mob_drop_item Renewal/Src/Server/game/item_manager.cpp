// Search for bool ITEM_MANAGER::CreateDropItem(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<LPITEM> & vec_item)
// after BYTE bRank = pkChr->GetMobRank(); add

#ifdef MOB_DROP_ITEM_RENEWAL
	int mMapIndex = pkChr->GetMapIndex();
#endif

// Search for 	
// Level Item Group
	// {
		// itertype(m_map_pkLevelItemGroup) it;
		// it = m_map_pkLevelItemGroup.find(pkChr->GetRaceNum());

		// if ( it != m_map_pkLevelItemGroup.end() )
		// {
			// if ( it->second->GetLevelLimit() <= (DWORD)iLevel )
			// {
				// __typeof(it->second->GetVector()) v = it->second->GetVector();

				// for ( DWORD i=0; i < v.size(); i++ )
				// {
					// if ( v[i].dwPct >= (DWORD)number(1, 1000000/*iRandRange*/) )
					// {
						// DWORD dwVnum = v[i].dwVNum;
						// item = CreateItem(dwVnum, v[i].iCount, 0, true);
						// if ( item ) vec_item.push_back(item);
					// }
				// }
			// }
		// }
	// }
	
// and after add

#ifdef MOB_DROP_ITEM_RENEWAL
	{
		itertype(m_map_pkMapIndexItemGroup) it;
		it = m_map_pkMapIndexItemGroup.find(pkChr->GetRaceNum());

		if ( it != m_map_pkMapIndexItemGroup.end() )
		{
			if ( it->second->GetMapIndex() == mMapIndex )
			{
				__typeof(it->second->GetVector()) v = it->second->GetVector();

				for ( DWORD i=0; i < v.size(); i++ )
				{
					if ( v[i].dwPct >= (DWORD)number(1, 1000000/*iRandRange*/) )
					{
						DWORD dwVnum = v[i].dwVNum;
						item = CreateItem(dwVnum, v[i].iCount, 0, true);
						if ( item ) vec_item.push_back(item);
					}
				}
			}
		}
	}
#endif