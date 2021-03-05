// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "大食堂");
        set("long", @LONG
泥土和石块搭成的房屋被烟熏火燎的漆黑，门口随地戳着个牌子，牌子上七
仰八岔地写着“大食堂”三个字，阵阵饭菜香从里面传出。大堂之上烛火通明，几
张方桌旁坐满了食客。黑乎乎的墙上用鲜血写着几个淋漓狂草(sign)！
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"zx",
  		"north" : __DIR__"storage",
	]));
	set("item_desc", ([
                "sign": @TEXT

                天高皇帝远，官少强盗多！
                青龙一抬头，四海尽奔腾！

       至此而南，尽我青龙会地界，遇民斩民，见官杀官！

TEXT,
            ]) );
	
	
    set("objects", ([
        __DIR__"npc/cavewaiter": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
/*
int valid_leave(object obj, string dir){
	if(dir == "south"){
		return notify_fail("还未开放区。。\n");
	}
	return 1;
}
*/
