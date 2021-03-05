#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","石室");
  set("long",@LONG
石室形作八角，共有八门，门上重帘垂地，分作红、橙、黄、绿、青、蓝、紫、
黑八色。暗色垂帘门前，有几具石榻玉几，放着些鲜果佳肴，香茶美酒，翠杯玉盏，
琳琅满目，美不胜收。
LONG
  );
  	set("exits",([
              ]));
          set("objects", ([
               BOOKS"skill/ill-quan_50" : 1, 
               __DIR__"npc/zhuzao" : 1,
       ]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
 }
 void init()
{
   add_action("do_open","open"); 
   add_action("do_close","close");
}
int do_close(string arg)
{
         object ob;
         switch (arg)
         {
         case "red":
         case "红门":
             if(!query("exits/red")) return notify_fail("门已经是关的了");
             message_vision("$N将红门关上\n",this_player());
             delete("exits/red");
             return 1;
         case "orange":
         case "橙门":
             if(!query("exits/orange")) return notify_fail("门已经是关的了");
             message_vision("$N将橙门关上\n",this_player());
             delete("exits/orange");
             return 1;
         case "yellow":
         case "黄门":
             if(!query("exits/yellow")) return notify_fail("门已经是关的了");
             message_vision("$N将黄门关上\n",this_player());
             delete("exits/yellow");
             return 1;  
         case "green":
         case "绿门":
             if(!query("exits/green")) return notify_fail("门已经是关的了");
             message_vision("$N将绿门关上\n",this_player());
             delete("exits/green");
             return 1;
         case "cyan":
         case "青门":
             if(!query("exits/cyan")) return notify_fail("门已经是关的了");
             message_vision("$N将青门关上\n",this_player());
             delete("exits/cyan");
             return 1;
         case "blue":
         case "蓝门":
             if(!query("exits/blue")) return notify_fail("门已经是关的了");
             message_vision("$N将蓝门关上\n",this_player());
             delete("exits/blue");
             return 1;
         case "mag":
         case "紫门":
             if(!query("exits/mag")) return notify_fail("门已经是关的了");
             message_vision("$N将紫门关上\n",this_player());
             delete("exits/mag");
             return 1;
         case "black":
         case "黑门":
             if(!query("exits/black")) return notify_fail("门已经是关的了");
             message_vision("$N将黑门关上\n",this_player());
             delete("exits/blk");
             return 1;

         default: return notify_fail("你要关什么？\n"); 
         }
         

}
int do_open(string arg)
{
         object ob;
         switch (arg)
         {
         case "red":
         case "红门":
             if(query("exits/red")) return notify_fail("门已经是开的了\n");
             message_vision("$N将红门打开\n",this_player());
             set("exits/red",__DIR__"redroom");
             return 1;
         case "orange":
         case "橙门":
             if(query("exits/orange")) return notify_fail("门已经是开的了\n");
             message_vision("$N将橙门打开\n",this_player());
             set("exits/orange",__DIR__"orgroom");
             return 1;
         case "yellow":
         case "黄门":
             if(query("exits/yellow")) return notify_fail("门已经是开的了\n");
             message_vision("$N将黄门打开\n",this_player());
             set("exits/yellow",__DIR__"yelroom");
             return 1;  
         case "green":
         case "绿门":
             if(query("exits/green")) return notify_fail("门已经是开的了\n");
             message_vision("$N将绿门打开\n",this_player());
             set("exits/green",__DIR__"grnroom");
             return 1;
         case "cyan":
         case "青门":
             if(query("exits/cyan")) return notify_fail("门已经是开的了\n");
             message_vision("$N将青门打开\n",this_player());
             set("exits/cyan",__DIR__"cynroom");
             return 1;
         case "blue":
         case "蓝门":
             if(query("exits/blue")) return notify_fail("门已经是开的了\n");
             message_vision("$N将蓝门打开\n",this_player());
             set("exits/blue",__DIR__"bluroom");
             return 1;
         case "mag":
         case "紫门":
             if(query("exits/mag")) return notify_fail("门已经是开的了\n");
             message_vision("$N将紫门打开\n",this_player());
             set("exits/mag",__DIR__"magroom");
             return 1;
         case "black":
         case "黑门":
             if(query("exits/black")) return notify_fail("门已经是开的了\n");
             message_vision("$N将黑门打开\n",this_player());
             set("exits/black",__DIR__"blkroom");
             return 1;
         default: return notify_fail("你要开什么？\n"); 
         }
         

} 
void reset()
{
	object zhuzao;
	::reset();
	if(!(zhuzao=present("zhu zao",this_object())))
		return;
	zhuzao->delete_temp("mark/pass_array");
}
	
int valid_leave(object me, string dir)
{      
    object ob;
    ob = present("zhu zao", this_object());

    if( objectp(ob) && !me->query_temp("mark/sucarray"))
	{
		return notify_fail("你必须过朱藻的七仙女阵才能离开这里的。\n");
	}
    return 1;
}           
