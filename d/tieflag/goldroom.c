#include <room.h>
inherit ROOM;
void create()
{
        set("short", "藏宝室");
        set("long", @LONG 
四面墙壁均是用玉做成，正对着你的是一块极大的[37m玉壁[32m。而房中壁上案头更都
摆满了奇珍异宝，无一件不是美到极处，华贵之极的精品，其中一柄剑鞘嵌满珠宝
的[37m长剑[32m似乎已经出鞘，剑光晶莹夺目，不可方物。
LONG
        );
         
       set("exits", ([ /* sizeof() == 2 */
  			"north" : __DIR__"gu5",
		]));
         
        set("item_desc", ([
                "sword": "这一看就是一把价值连城的宝剑，剑身是弯的（pull sword）\n",
                "宝剑": "这一看就是一把价值连城的宝剑，剑身是弯的（pull sword）\n",
				"玉壁": "一整块晶莹的美玉，仿佛经常有人用手触摸（pull sword）\n", 
                "jade": "一整块晶莹的美玉，仿佛经常有人用手触摸（pull sword）\n",
                "玉壁":"玉壁像一扇小门，遮住了后面的景色（push jade）\n",
                "jade":"玉壁像一扇小门，遮住了后面的景色（push jade）\n",	
        ]) );

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
      
}
 
 void init()
{
   add_action("do_open","push"); 
   add_action("do_pull","pull");
}

         


int do_open(string arg)
{
	object room;
         object me;  
	me=this_player();
	if(!objectp(room = find_object(__DIR__"girlroom")))
	room = load_object(__DIR__"girlroom");
	switch (arg)
         {
         case "jade":
         case "玉壁":
             if(query("exits/east")) return notify_fail("门已经是开的了。");
             message_vision("$N伸手在玉壁上一按，玉壁上出现一扇小门。\n",this_player());
             set("exits/east",__DIR__"girlroom");
			room->set("exits/west",__DIR__"goldroom");
	     	call_out("closepath",5,room);
             return 1;
         }
}

void closepath(object room)
{
	tell_object(this_object(),"小门＂吱＂的一声又关上了。\n");
	delete("exits/east");
	room->delete("exits/west");
}
int do_pull(string arg)
{
        object swo;
		string *limbs;
		if( query_temp("mark/been_get")) return notify_fail("剑已被拔走了。\n");
		if(random(this_player()->query_kar()) > 19 && random(100)>90)
        { 
			swo=new(__DIR__"obj/leavehook");
			swo->move(this_player());
			set_temp("mark/been_get",1);
			write("你从墙上拔下了一柄离别钩。\n" );
		}
		else
        { 
			limbs=this_player()->query("limbs");
			write("你试着去拔剑，剑光一闪．．．\n");
			write("你的"+limbs[random(sizeof(limbs))]+"被剑气所伤。\n");
        	this_player()->receive_damage("kee",random(100)+1);
			this_player()->set_temp("last_damage_from","在大旗谷意图劫宝不慎累死。");
			COMBAT_D->report_status(this_player(),0);
		}
        
        return 1;

}

void reset()
{
    	::reset();
		delete_temp("mark/been_get");
}
