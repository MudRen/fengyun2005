inherit ROOM;

void create()
{
	set("short", "狼牙岭");

	set("long", @LONG
群山一眼望不到尽头，狼牙般狰狞钩连。天色陡然变得低沉灰涩，几乎压得你
喘不过气来，远处不时传来阵阵哀鸣悲号，你仿佛置身于无边无尽的梦魇之中无法
逃逸。北面上行便是一夫当关，万夫莫开的狼笔峰，而东面山壁上赫然是条傍着悬
崖而建的险要栈道。
LONG);

	set("type","mountain");
	set("exits",([
		"eastdown":__DIR__"cliffroad1",
		"southup":__DIR__"wolfhill2",
		"northdown":__DIR__"18pan1",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/tuoba":1,
    	]) );
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("tuoba zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/狼山游客") )
                {                
                        return notify_fail(ob->name()+"身形一闪拦住去路，粗声喝道：此处乃我狼山重地，请回！！！\n");
		}
	}
	return 1;
}
