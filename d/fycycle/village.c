inherit ROOM;
void create()
{
        set("short", "草堂");
        set("long", @LONG
两旁修竹姗姗，花径鹅卵石上生满青苔，显得平素少有人行。花径通到三间石
屋之前。屋前屋后七八株苍松夭矫高挺，遮得四下里阴沉沉的。石屋旁一座草堂，
左右各植一棵老梅，枝干如铁，极是苍劲。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east":      __DIR__"lake",
	]));
	set("objects", ([
        	__DIR__"npc/meida": 1,
        ]) );
	
	set("coor/x",-120);
	set("coor/y",-320);
	set("coor/z",0);
        setup();
}


int valid_leave(object who, string dir) {
	object ob;
	
	if (dir == "east") {
		if (who->query_temp("marks/cheat_meida")+ 120 > time()
			&& ob = present("mei da", this_object()))
			return notify_fail("梅大先生冷冷地说：没付诊金就想走？在这儿反省一阵吧。\n");
	}
	return ::valid_leave(who, dir);	
}
