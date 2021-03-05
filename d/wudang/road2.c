inherit ROOM;

void create()
{
	set("short", "上山路");
	set("long", @LONG
弯弯曲曲的泥土路，却很平坦。左右两边都是茂盛的松林，雨过天晴时，泥土
的香气和松树的芬芳混在一起，能使人心胸开朗，忘记一切烦恼。不远的前方，有
一块巨石和一个小亭子。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"gate",
		"southup" : __DIR__"xuanwumen",
		"west" : __DIR__"pine1",
		"east" : __DIR__"pine3",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",-40);
	setup();
}


int valid_leave(object obj, string dir){
	object /**inv,*/ *npc,room;
	int i, j;
	
	if (dir != "east")
		return ::valid_leave(obj, dir);

	room = find_object(__DIR__"pine3");
	if (!room) room = load_object(__DIR__"pine3");
	
	npc = all_inventory(room);
//npc = filter_array(inv, (: $1->query("id") == "taoist elder" :));
	
	j = 0;
	if (npc)
	for(i=0; i<sizeof(npc); i++) {
		if (npc[i]->is_fighting())
			return notify_fail("林子里剑风凌厉，你竟然无法靠近。\n");
		if (userp(npc[i]))	j++;		
	}
	
	if (j>=4)
		return notify_fail("林间空地狭小，已经没法容下更多的人了。\n");
	
	room->reset();
				
	return ::valid_leave(obj, dir);
}