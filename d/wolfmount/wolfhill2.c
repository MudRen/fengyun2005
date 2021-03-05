inherit ROOM;

void create()
{
	set("short", "狼笔峰");

	set("long", @LONG
山路到了这里突然陡峭起来，两旁山峰笔立如刀，中间留出一条窄窄的山路，
已是两人不能并肩而行。正所谓“黄鹤之飞尚不得，猿猱欲度愁攀援”。凛冽的山
风猎猎作响，如同快刀割在你的脸上，手上，身上．．．．．．
LONG);

	set("type","mountain");
	set("exits",([
		"northdown":__DIR__"wolfhill",
		"southwest":__DIR__"wolfslope",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
            __DIR__"npc/geshu":1,
    	]) );
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",-10);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southwest" && ob=present("zhongli zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/狼山游客") )
                {                
                        return notify_fail(ob->name()+"身形一闪拦住去路，粗声喝道：此处乃我狼山重地，请回！！！\n");
		}
	}
	return 1;
}
