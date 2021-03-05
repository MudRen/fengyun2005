#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
    set("short", "草坪");
    set("long", @LONG
这是一片碧绿的草坪，踩上去觉得异常的柔软温厚，草坪一直延伸到小河畔，
青青草根也浸入河水之中。河面上点点烁金，波纹轻轻荡漾。草坪的南面，一棵高
大的梧桐树，枝干斜伸，两根古藤粗粗挽就一个秋千。
LONG
        );
    	set("exits", ([
		"west" : __DIR__"livingroom",
	]) );

    	set("item_desc", ([
        "qiuqian":"秋千系用古藤挽就，虽然简陋，却别有情趣。你可以试着荡荡看。（ｓｗｉｎｇ）\n",
        "qiu qian":"秋千系用古藤挽就，虽然简陋，却别有情趣。你可以试着荡荡看。（ｓｗｉｎｇ）\n",
        "秋千":"秋千系用古藤挽就，虽然简陋，却别有情趣。你可以试着荡荡看。（ｓｗｉｎｇ）\n",
        "tree":"高大的梧桐树把草坪的北方遮的严严实实。\n",
        "梧桐树":"高大的梧桐树把草坪的北方遮的严严实实。\n",
	]) );

	set("no_magic", 1);
    	set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
    	setup();
}

init()
{
	add_action("do_swing", "swing");
    	add_action("do_north", "go");
}

int do_north(string arg)
{
    	object room, me;
    	me = this_player();

	if (arg == "north") {
    		tell_object(me, "你绕过梧桐树，拨开草丛，惊奇地发现这里居然别有洞天．．．\n\n");
    		room=find_object(__DIR__"shuhou");
    		if(!objectp(room)) room=load_object(__DIR__"shuhou");
    		me->move(room);
    		return 1;
    	}
}

int do_swing(string arg)
{
    object me;

    me = this_player();

    	if(!arg || arg != "秋千" && arg != "qiu qian" && arg !="qiuqian" )
        	return 0;
    	switch (random (4))
    {
	    case 0:
	        message_vision(HIG"$N爬到秋千上，慢慢地开始荡起秋千，越荡越高。\n"NOR,
	                       me);
	        break;
	    case 1:
	        message_vision(HIG"秋千越荡越高，$N不由得紧紧抓住古藤。\n"NOR, me);
	        tell_object(me, "你只觉得风从脚底掠过，人似乎要乘风飞去。\n");
	        break;
	    case 2:
	        message_vision(HIG"秋千越荡越高，$N不由得紧紧抓住古藤。\n"NOR, me);
	        message("vision", me->name()+
	                "似乎看到了什么东西，匆匆地从秋千上跳了下来。\n",
	                environment(me), me);
	        tell_object(me,"你忽然发现有东西在书房内发出耀眼的光，光一闪即失。\n");
	        me->set_temp("marks/marble", 1);
	        break;
	    case 3:
	        message_vision(HIR"秋千越荡越高，$N一不留神从秋千上掉了下来。\n"NOR,
	                       me);
	        tell_object(me, "“砰！”你重重地摔在树根上，屁屁好痛哦！ \n");
	        me->receive_damage("gin",10);
	        me->receive_damage("kee",10);
	        me->receive_damage("sen",10);
	        me->set_temp("last_damage_from","荡秋千摔死了。\n");
	        break;
    }
    return 1;
}
