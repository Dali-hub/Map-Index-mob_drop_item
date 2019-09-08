// Search for bool ITEM_MANAGER::ReadMonsterDropItemGroup(const char * c_pszFileName)
// after int iLevelLimit = 0; add

#ifdef MOB_DROP_ITEM_RENEWAL
		int iMapIndex = 0;
#endif

// Search for sys_log(0,"MOB_ITEM_GROUP %s [%s] %d %d", stName.c_str(), strType.c_str(), iMobVnum, iKillDrop);
// before this add

#ifdef MOB_DROP_ITEM_RENEWAL
		if ( strType == "index" )
		{
			if ( !loader.GetTokenInteger("map_index", &iMapIndex) )
			{
				sys_err("ReadmonsterDropItemGroup : Syntax error %s : no map_index, node %s", c_pszFileName, stName.c_str());
				loader.SetParentNode();
				return false;
			}
		}
		else
		{
			iMapIndex = 0;
		}
#endif

// Search for 
//			m_map_pkLevelItemGroup.insert(std::map<DWORD, CLevelItemGroup*>::value_type(iMobVnum, pkLevelItemGroup));
//		}
// after this add

#ifdef MOB_DROP_ITEM_RENEWAL
		else if ( strType == "index" )
		{
			CMapIndexItemGroup* pkMapIndexItemGroup = M2_NEW CMapIndexItemGroup(iMapIndex);

			for ( int k=1; k < 256; k++ )
			{
				char buf[4];
				snprintf(buf, sizeof(buf), "%d", k);

				if ( loader.GetTokenVector(buf, &pTok) )
				{
					std::string& name = pTok->at(0);
					DWORD dwItemVnum = 0;

					if (false == GetVnumByOriginalName(name.c_str(), dwItemVnum))
					{
						str_to_number(dwItemVnum, name.c_str());
						if ( !ITEM_MANAGER::instance().GetTable(dwItemVnum) )
						{
							sys_err("ReadDropItemGroup : there is no item %s : node %s", name.c_str(), stName.c_str());
							M2_DELETE(pkMapIndexItemGroup);
							return false;
						}
					}

					int iCount = 0;
					str_to_number(iCount, pTok->at(1).c_str());

					if (iCount < 1)
					{
						sys_err("ReadMonsterDropItemGroup : there is no count for item %s : node %s", name.c_str(), stName.c_str());
						M2_DELETE(pkMapIndexItemGroup);
						return false;
					}

					float fPct = atof(pTok->at(2).c_str());
					DWORD dwPct = (DWORD)(10000.0f * fPct);

					sys_log(0,"        name %s pct %d count %d", name.c_str(), dwPct, iCount);
					pkMapIndexItemGroup->AddItem(dwItemVnum, dwPct, iCount);

					continue;
				}

				break;
			}

			m_map_pkMapIndexItemGroup.insert(std::map<DWORD, CMapIndexItemGroup*>::value_type(iMobVnum, pkMapIndexItemGroup));
		}
#endif
