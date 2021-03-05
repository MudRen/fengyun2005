//anniew.

#include <ansi.h>
inherit ROOM;
void warning(object me);
void capture(object me);
void create()
{
        set("short", "荒园");
        set("long", @LONG
转过荷花荡，景色倏然一变，雾色凄迷，寒鸦掠过，小路上荒草没径，荷塘里
也落满了枯叶。尽头的枯木林中小楼一角，依稀就是当年小李探花读书学剑的冷香
小筑，如今却早已荒废，爬满了蛛网积尘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"southwest" : __DIR__"hehuadang2",
	]));
        set("outdoors","qianjin");

        set("coor/x",-20);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        
}

void init()
{
        object me = this_player();
        object room;
        add_action("do_search","search");
        
        remove_call_out("warning");
        remove_call_out("capture");
        if (	me->query("age") >13 
        	&& !NATURE_D->is_day_time()
                && me->query("age") <26 
                && !me->query_temp("afei_on_the_way")
                && me->query("combat_exp")>300000 
                && me->query("gender") == "女性" 
		) 
        {
                room = find_object(__DIR__"basement");
                if (!objectp(room)) room = load_object(__DIR__"basement");
                if (present("meihua dao",room))
                if (!objectp(room->query("occupied")))       // 每次只抓一个
                	call_out("warning", 10, me);
        }
        
}

void warning(object me) {
        if (environment(me) == this_object() ) {
        tell_object(me, WHT"\n荒园里寒鸦凄厉，落叶疏萧，一种危险的预感让你觉得非常不安。\n\n"NOR);
                call_out("capture", 5, me);
        }
        
}

void capture(object me) {
        object room;
        if (environment(me) == this_object() ) {

        	message_vision(HIB"
枯木林中忽然卷起一阵阴冷的风，寒飕飕的自你脸上刮过。你霎了霎眼，
突然觉得似乎有个阴影站在$N的身后。$N悚然一惊，正想转身，却已被
点中了穴道。


阴影将$N挟在肘下，腾云驾雾般的掠了出去．．．\n\n"NOR, me);
                room=find_object(AREA_QIANJIN"basement");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"basement");
                room->set("occupied",me);
                room->reset();
                me->set_temp("marks/meihuadao", 1);
                me->move(room);         
             	message_vision(HIR"
梅花盗将$N丢到了地下室角落里的小床上，一阵莫可名状的气味袭来，
$N气息一窒，晕了过去。\n"NOR,me);
             	me->unconcious();
        }
}

int do_search() {
        object me = this_player();
	object room;
	
	room = find_object(__DIR__"basement");
	if (objectp(room))
        if (me->query_temp("afei_on_the_way") && objectp(room->query("occupied")) ) {
                tell_object(me, WHT"\n荒园里寒鸦凄厉，落叶疏萧，一种危险的预感让你觉得非常不安。\n\n"NOR);
                message_vision("$N拨开枯叶，发现地面有一个洞口。\n", me);
                if( !query("exits/down") ) {
                        set("exits/down", __DIR__"basement");
                        call_out("close_path", 2);                
                        
                }
                return 1;
        }
        me->delete_temp("afei_on_the_way");// Room Player probably quitted. Need restart.Or need ask afei
        tell_object(me,"你什么也没发现（ＲＰＧ提示：你不是正角儿或有什么事儿还没做）\n");
        return 1;
}


void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"一阵风吹起片片枯叶，纷纷扬扬地落下，遮蔽了地上的洞口。\n",
                this_object() );
                delete("exits/down");
}


void wine_notify(object who)
{
        object deer;

        deer = present("li huai", this_object());
        if(!objectp(deer))
        {
                deer = new(__DIR__"npc/lihuai");
                deer->move(this_object());
                message_vision(CYN"
一个风尘仆仆的少年人，穿一身灰扑扑的衣裳，懒洋洋地走了出来。
少年人一见到$N手中的酒葫芦，眼神就开始发亮。
还不等$N说话，他就笑着道：一定是公孙先生让你来的，是有阿素的消息了么？\n\n"NOR,who);
                REWARD_D->riddle_set(who,"两世恩怨",9);
         //     who->set("annie/riddle/moonmaster",9);
        }
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

