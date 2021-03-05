//Created by justdoit at May 2001 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "接天楼");
    set("long", @LONG
危乎高哉！接天而立，比天之高！叶孤城心怀天下，立志有朝一日逐鹿中原。而
此楼地处白云岛最高之处，仿佛一柄利剑划破长空遥指中原九州。楼上别无他物，一
座高台上汉白玉雕成的龙椅面北迎风。
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"yuequedian",
	//       "south" : __DIR__"changlang",
      ]));
    set("item_desc", ([
	"chair": "这是一张巨大的汉白玉雕成的龙椅，两侧扶手是两条张牙舞爪的龙，
两条龙舌长长的伸出来，似乎可以分别扭动(twist)。\n",
	"龙椅": "这是一张巨大的汉白玉雕成的龙椅，两侧扶手是两条张牙舞爪的龙，
两条龙舌长长的伸出来，似乎可以分别扭动(twist)。\n",
      ]) );
    set("objects", 
      ([ 
	"/obj/specials/ding/ding_by":	1,	
	__DIR__"npc/fakemaster" : 1,
	__DIR__"npc/jiankuang" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-240);
    set("coor/z",30);
    setup();
}


void init()
{
    add_action("do_twist", "twist");
}


int do_twist(string arg)
{
    object me;
    me = this_player();
    if(arg != "left" && arg != "right")
	return notify_fail("你要扭动哪边的龙头？（right or left）\n");
    
    if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙。\n");
    
    if (REWARD_D->riddle_check(me,"王图一梦") !=10 )
    {
		if (present("jian kuang",this_object()) && !userp(present("jian kuang",this_object())))
		{
		    present("jian kuang",this_object())->ccommand("bite");
		    present("jian kuang",this_object())->ccommand("say 吾师在此，休得胡来。");
		    return 1;
		}
		if (present("Master ye",this_object()) && !userp(present("Master ye",this_object())))
		{
		    present("Master ye",this_object())->ccommand("heng");
		    present("Master ye",this_object())->ccommand("say 老夫面前也敢放肆？");
		    return 1;
		}
    }
    
    if (arg == "left")
    {
		message_vision(YEL"$N扭动了一下椅上的龙头。
咯吱吱一声巨响，龙椅往边上挪了开去，后面出现条黑森森的洞口。
$N掩不住好奇之心，小心翼翼地走进洞中。\n"NOR,me);
		me->move(load_object(__DIR__"changlang"));
		me->perform_busy(1);
		message("vision",me->name()+"走了过来。",environment(me),me);
		return 1;
    }
    
    message_vision(YEL"$N扭动了一下椅上的龙头。
咯吱一声：地板突然翻开，$N惨叫一声掉了下去。\n"NOR,me);
    me->move(load_object(__DIR__"pailangya"));
    me->perform_busy(1);
    message("vision",me->name()+"掉了下来。",environment(me),me);

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
