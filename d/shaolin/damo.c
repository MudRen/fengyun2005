// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
    set("short", "达摩院");
    set("long", @LONG
这里是达摩悟禅之处，院内陈设极为简单，四周墙壁密密麻麻挂满了条幅，几
个老僧须发皆白，正在埋首苦思，如中魔魇，一旦苦思有了结果，便立刻挥笔书于
条幅之上，大家印证。
LONG
        );
    set("exits", ([ 
        "east" : __DIR__"xiji",
        "west" : __DIR__"jiangwu",
        "north": __DIR__"cj",
        "south": __DIR__"luohan",
        ]));
    set("objects", ([
        __DIR__"npc/master_18" : 1,
        __DIR__"npc/laomonk" : 2,
        ]) );
	set("coor/x",0);
	set("coor/y",90);
	set("coor/z",20);
    setup();
}

int valid_leave(object me, string dir)
{
    object ob;
    
    	if (ob=present("old monk", this_object()))
	if( userp(me) && dir=="north" 
			&& me->query("vendetta/shaolin")>=1) 
		return notify_fail(ob->query("name")+"喝道:贼子止步!\n");

    // free pass
    	if (me->query("family/master_id") =="damo") return 1;
    	if (me->query("family/generation")<=18 && me->query("class")=="shaolin") return 1;
    
   
    // to non-shaolin student   
/*    if (dir == "north" && me->query("family/family_name") != "少林寺"){
       	if (ob=present("old monk", this_object()))
    		return notify_fail(ob->query("name")+"说道：施主请留步。\n");
    	if (ob=present("master yi", this_object()))
    		return notify_fail(ob->query("name")+"长袖一挥，你被挡了回来。\n");
    }*/ 
    
    // to shaolin student
    if (dir == "north" && me->query("family/family_name") == "少林寺") 
    	if (me->query("family/generation") > 18 && (!me->query_temp("won_master_yi"))) {
    	  message_vision("一股大力将$N推了回来，一个苍老的声音说道：过了一尘长老这一关，才可以闯木人巷。\n",me);
        return notify_fail("");
    } 

    
    return 1;
}
