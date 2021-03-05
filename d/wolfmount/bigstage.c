inherit ROOM;

void create()
{
	set("short", "烽火台");

	set("long", @LONG
这里是一块很大的岩石，形成了一个天然的宽阔平台。远远望去，前方青山欲
滴，层峦叠嶂，正是狼山。据说狼山有很多狼，天下大大小小、公公母母、各式各
样的狼，都是从狼山来的，等到它们将死的时候，也都要回狼山去死。但凡有富贾
高官经过附近，狼山群盗们必然在此燃起狼烟，蜂拥而下杀人越货。
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"18pan4",
		"eastdown":__DIR__"yinroad3",
		"westdown" : AREA_GUANWAI"shudao2",
	]) );
	set("outdoors", "wolfmount");
	set("objects",([
		__DIR__"npc/fwolf":1,
		__DIR__"npc/fwolfa":1,
    	]) );
    	set("type", "road");
	set("coor/x",-20);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("fighter wolf", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/狼山游客") )
                {                
                        return notify_fail(ob->name()+"伸手拦住去路，说道：＂闲杂人等不得随便进入我狼山！！！\n");
		}			
	}
	return 1;
}
