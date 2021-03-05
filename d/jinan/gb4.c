// Tie@fy3
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","大厅");
  set("long",@LONG
大厅里排着两行紫檀木椅子，这里便是丐帮帮主与一众长老议事的地方。正中
太师椅上垫着柔软的貂皮靠枕，脚下铺着白虎皮垫，若不是壁上挂着丐帮祖师爷乌
鲁汉和洪七公的画像，还以为是到了什么富豪之家。
LONG
  );
  	set("exits",([
        	 "south":__DIR__"gb1",
                 "north":__DIR__"private",
               ]));
        set("objects", ([
                __DIR__"npc/master4" : 1,
       	]) );
        set("coor/x",-20);
        set("coor/y",100);
        set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        
        if (REWARD_D->check_m_success(me,"魂断鹊桥"))	
        	return ::valid_leave(me,dir);
        
        if( dir == "north" && ob=present("master nangong", this_object()))
                return notify_fail("这个方向的路被"+ob->name()+"挡住了 。\n");
        return 1;
}
