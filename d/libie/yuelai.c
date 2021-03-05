// Room: yuelai.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "悦来客栈");

	set("long", @LONG
这算是小县城里最大的客栈了，房子也是新盖的，可前几天却突然花了数百两
银子把楼上的套间重新装修了一遍。客栈老板也贴出告示拒不待客。私底下老板透
出消息说这一切仅仅是因为世袭一等侯狄青麟小侯爷要在楼上新盖的“麒麟阁”住
一晚上。
LONG);

	set("type","house");
	set("exits",([
		"up":__DIR__"corridor",
		"north":__DIR__"stoneroad2",
	]) );

        set("objects", ([
                __DIR__"npc/owner": 1 ]) );

        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);

	setup();
}
	

int valid_leave(object me, string dir)
{
    object ob,cloth;
        if( dir == "up" && ob=present("lao ban", this_object()))
        {
        	cloth=present("waiter cloth",me);
        	if(objectp(cloth))
        	if(cloth->query("equipped"))
        		return 1;
        	        		
         	return notify_fail("老板双手一张挡住去路，恨声道：你个" 
         		+ RANK_D->query_rude(this_player()) + "，不想活了啊，惊了狄小侯爷那还了得！\n");
    	}
        return 1;
}