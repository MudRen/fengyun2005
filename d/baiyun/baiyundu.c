#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"白云渡"NOR);
    set("long", @LONG
白云幽幽，海天一线。这里，就是白云岛了，但见阳光灿烂，岛边沙滩洁白柔细，
海水湛蓝如碧，浪涛带着新鲜美丽的白沫轻拍着海岸，晴空万里无云，岛上满眼翠绿。
一切有如仙境一般。靠着岸边是个不大的[37m码头[32m，停靠着来往白云岛的船只，嘹亮的呼
声此起彼落，原来来往的游人只要呼唤码头的船家即可雇船离岛。
LONG
    );    
    set("exits",       
      ([        
	"south" : __DIR__"huangsha1",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ])); 
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y", 0);
    set("coor/z",0);
    set("item_desc", ([
	"码头": "白云岛的码头不大，也格外的繁忙，三两个白发的老伯，两三叶简易的木筏，你\n
如果想搭乘，不妨招呼（yell）老伯们一声。\n",
               "matou": "白云岛的码头不大，也格外的繁忙，三两个白发的老伯，两三叶简易的木筏，你\n
如果想搭乘，不妨招呼（yell）老伯们一声。\n",
               "dock": "白云岛的码头不大，也格外的繁忙，三两个白发的老伯，两三叶简易的木筏，你\n
如果想搭乘，不妨招呼（yell）老伯们一声。\n",
        ]) );

	setup();
}

void init()
{               
        add_action("do_yell","yell");
}

void boat_come(object who)
{
	object byboat;
	object oldman;
	object *inv;
	int i;

	if (environment(who)!= this_object())	return;
		
	if (!objectp(byboat=find_object(__DIR__"boat2")))
		byboat=load_object(__DIR__"boat2");
	 message_vision(CYN"船家老伯笑眯眯地应了一声，长篙轻点，木筏小舟便已靠在码头边上。\n"NOR,who);
	message_vision(WHT"船家老伯跳上海岸，笑呵呵道：“客官，上船吧！”\n"NOR,who);
	set("exits/down",__DIR__"boat2");
	call_out("boat_leave",3,byboat);
}


void boat_leave(object byboat)
{
	if (query("exits/down")) 
	delete("exits/down");
	if (byboat->query("exits/up")) 
                byboat->delete("exits/up");
	message("vision","船家老伯松开了缆绳，海水将小舟缓缓推离岸边．．．\n",this_object()); 
    byboat->set_temp("mark/dest","island");
	message("vision","船家老伯松开了缆绳，海水将小舟缓缓推离岸边．．．\n",byboat);
}



int do_yell()
{
	object me;
	object room;
	me = this_player();
	message_vision(CYN"$N向船家老伯高声招呼道，“船家，回南海！”\n"NOR , me );
	call_out("boat_come",1,me);
	return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
