#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断墙边");

	set("long", @LONG
原本就摇摇欲坠的断塔在两大高手的剧斗之下只剩下一片残墙断垣。四周一片
寂静。晚风吹过，只有塔下的那棵银杏树在风中划划做响，树影婆娑，如泣如诉。	
LONG);

	set("type","street");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",-10);
	set("exits",([
		"east":__DIR__"undertower",
	]));
		
	set("objects",([
		__DIR__"obj/brokenwall":1
	]) );
	set("outdoors", "bawang");
	setup();
}

void init ()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	if(!arg || arg=="")
	{
		write("你要打开什么？\n");
		return 1;
	}
	if( arg == "duanqiang" || arg == "断墙" || arg == "残墙" 
		|| arg == "wall" || arg == "残墙断垣")
	{
		object me, room;
		me = this_player();
		if(me->query("kar")+random(50) < 25){
			message_vision(HIY"$N运气于双臂，牙关紧咬，双目圆睁。大喝一声：“开！”\n\n"NOR, me);
			if(me->query("gender") == "male"){
				message_vision(HIY"只听“嘣！”的一声！\n\n"NOR, me);
				message_vision(HIY"$N的裤腰带绷断了......\n"NOR, me);
			} else {
				message_vision(HIY"$N俏面憋得通红，断墙还是纹丝不动。\n"NOR, me);
			} 	
		return 1;
		}
		if(me->query("str") < 14){
			tell_object(me,HIR"尽管是危墙，但是你手无缚鸡之力，使了吃奶的力气，断墙还是纹丝不动。\n");
			return 1;
		} else if(me->query("str") + random(20) < 24) {
			tell_object(me,HIR "你用力一推，断墙似乎有些晃动。“啪！”你觉得头顶一阵剧痛。
原来是一块砖头从墙头被你晃落下来，正拍在你头顶上!你觉得一阵天旋地转。\n"NOR);
			me->set_temp("last_damage_from","被砖头砸死了。\n");
			me->receive_damage("kee",random(100)+30);
			me->receive_damage("gin",random(100)+30);
			return 1;
		 }else{
			message_vision(HIW"\n$N运气于双臂，牙关紧咬，双目圆睁。大喝一声：“开！”\n\n", me);
			message_vision(HIW"只听“轰隆”一声，断墙一下子倒了下来。\n\n"NOR, me);
			tell_object(me, "在残砖断瓦之后你似乎找到了一个隐秘的入口。\n");
			if( !query("exits/enter") ) {
				set("exits/enter", __DIR__"andao1.c");
				call_out("close_path", 3);	
			}
			return 1;
		}
	}
}

void close_path()
{
	if( !query("exits/enter") ) return;
	message("vision", "残砖断石纷纷落下。。。。\n",this_object());
	delete("exits/enter");
}
