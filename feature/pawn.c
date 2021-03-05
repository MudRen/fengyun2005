
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <dbase.h>

mapping pawn;
mapping vpawn;
mapping fpawn;

mapping pawn2;
mapping vpawn2;
mapping fpawn2;

mapping query_pawn() { return pawn; }
mapping query_vpawn() { return vpawn; }
mapping query_fpawn() { return fpawn; }

mapping query_pawn2() { return pawn2; }
mapping query_vpawn2() { return vpawn2; }
mapping query_fpawn2() { return fpawn2; }

void set_pawn(string num, string name)
{
	if( !mapp(pawn) ) pawn= ([ num: name ]);
	else pawn[num] = name;
}
void set_vpawn(string num, int val)
{
        if( !mapp(vpawn) ) vpawn= ([ num: val]);
        else vpawn[num] = val;
}
void set_fpawn(string num, string name)
{
        if( !mapp(fpawn) ) fpawn= ([ num: name ]);
        else fpawn[num] = name;
}

int delete_pawn(string num)
{
	if( mapp(pawn) ) {
		map_delete(pawn, num);
		return undefinedp(pawn[num]);
	}
	return 0;

}
int delete_vpawn(string num)
{
        if( mapp(vpawn) ) {
                map_delete(vpawn, num);
                return undefinedp(vpawn[num]);
        }
        return 0;

}
int delete_fpawn(string num)
{
        if( mapp(fpawn) ) {
                map_delete(fpawn, num);
                return undefinedp(fpawn[num]);
        }
        return 0;

}


void set_pawn2(string num, string name)
{
	if( !mapp(pawn2) ) pawn2= ([ num: name ]);
	else pawn2[num] = name;
}
void set_vpawn2(string num, int val)
{
        if( !mapp(vpawn2) ) vpawn2= ([ num: val]);
        else vpawn2[num] = val;
}
void set_fpawn2(string num, string name)
{
        if( !mapp(fpawn2) ) fpawn2= ([ num: name ]);
        else fpawn2[num] = name;
}

int delete_pawn2(string num)
{
	if( mapp(pawn2) ) {
		map_delete(pawn2, num);
		return undefinedp(pawn2[num]);
	}
	return 0;

}
int delete_vpawn2(string num)
{
        if( mapp(vpawn2) ) {
                map_delete(vpawn2, num);
                return undefinedp(vpawn2[num]);
        }
        return 0;

}
int delete_fpawn2(string num)
{
        if( mapp(fpawn2) ) {
                map_delete(fpawn2, num);
                return undefinedp(fpawn2[num]);
        }
        return 0;

}


