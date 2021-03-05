// 小小少林寺
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "茅屋内");
        set("long", @LONG
小门里这小小一间茅屋，布置得竟是精致华丽已极，四面锦帐流苏，牙床妆台，
床上堆着翠衾，台上悬着明镜，镜旁还有几副女子梳髻用的木梳。风吹锦帐，露出
里面墙壁，墙壁竟是青铜所制。屋角有一土坑，深达地下。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "down"  : __DIR__"didao",
        "north" : __DIR__"maoroom",
]));

        set("item_desc", ([
                "木梳": "一把女子用的木梳，梳上还缠着几根青丝。\n",
				"comb" :"一把女子用的木梳，梳上还缠着几根青丝。\n",
                "妆台" :"一个红木妆台，台上压着个纸柬，下面有一个"YEL"小柜\n"NOR,
                "desk" :"一个红木妆台，台上压着个纸柬，下面有一个"YEL"小柜\n"NOR,
                "小柜" :"这个小柜你可以拉开它（ｐｕｌｌ）\n",
                "cabinet" :"这个小柜你可以拉开它（ｐｕｌｌ）\n",
                "纸柬" :@TEXT
上面写的是：
    我终于自由了，你寻我不到，还是死了这条心吧，你为我受的苦，
都是你自愿的，你活该！
                                                   阴宾留。
                                                      
TEXT,                                                  
                "paper" :@TEXT
上面写的是：
    我终于自由了，你寻我不到，还是死了这条心吧，你为我受的苦，
都是你自愿的，你活该！
                                                   阴宾留。
                                                      
TEXT                                                  
                                              
        ]) );
//        set("objects",([
//                       __DIR__"npc/drinkmonk2" : 1,
 //                     ])  );
           
 
	set("coor/x",90);
	set("coor/y",-100);
	set("coor/z",0);
	setup();

}

void init()
{
   add_action("do_pull","pull");
}                  

void reset()
{
    ::reset();
    delete("mark/阴宾");
}


int do_pull(string arg)
{
         object yinbin, monk;
         if (arg!="小柜" && arg != "cabinet") return notify_fail("你要拉开什么？\n");
         if (monk=present("drink monk",this_object()))
         	return notify_fail(monk->name()+"说：你想干什么？\n");
         if(query("mark/阴宾")) 
         	return notify_fail("你拉开小柜，里面什么也没有。\n");         
         message_vision("$N将小柜打开\n",this_player());
         message_vision(HIR "$N觉得眼前一花，室中已多了一个身材修长、体态婀娜，身穿轻红罗衫的宫髻美人。\n"NOR,this_player());
         this_object()->set("mark/阴宾",1);        
         this_player()->set_temp("mark/阴宾",1);
         yinbin=new(AREA_TIEFLAG"npc/yinbin");
         yinbin->move(environment(this_player()));
         return 1;
}

int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "down")
        	message_vision("$N手脚并用，爬进地道。\n",me);

        return 1;
}
