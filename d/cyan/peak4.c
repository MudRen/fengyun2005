// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "古瞭望台");
    set("long", @LONG
登上残破的古瞭望台，视野一片开阔。迎视壁立万仞，俯视丛林深壑，只
向西再迈一步，便会坠入白雾茫茫的深渊。你移步换形，与云同幻，回想当年
烽火金戈，遗留给如今世人的不过一座业半倒塌的土楼，那时光阴再难被人忆
起，心底一阵萧然。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/shri":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"down" : __DIR__"peak3",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",100);
	setup();
}

void init()
{
	add_action("do_west","go");
}

int do_west(string arg)
{
	object me = this_player();
	int i;
	if (arg != "west")
		return 0;
	if (me->query("combat_exp") < 1000000)
	{
		tell_object(me,WHT"你向瞭望台下窥望，只见白雾叠叠，飒隐萧萧，不禁止住脚步。\n"NOR);
		return 1;
	}

	if (me->is_fighting())
		message_vision("$N见情况不对，疾奔两步，纵身向瞭望台外跳去。\n",me);
	else
		message_vision("$N长吸一口气，闭上眼睛，纵身向瞭望台外跳去。\n",me);

	i=me->query_skill("move");
	if (me->is_fighting())
		i=i*3/4;
	tell_object(me,HIW"\n层层的白云在身边掠过，拍打在脸上的疾风带着刺骨的寒意，你的心提到了嗓子眼里．．\n"NOR);
	me->perform_busy(3);
    me->set_temp("disable_inputs",1);
	me->add_temp("block_msg/all",1);
   	me->delete("timer/lifesave");	// 落花流水一起去:p
	me->move("/obj/void");
	me->set_temp("last_damage_from","在明霞山跳崖自尽了。");
	call_out("jump_down",6,me,i);

	return 1;


}


int jump_down(object me,int i)
{
	object room;
	if(!objectp(me)) return 1;
  	if (me->is_ghost()) return 1;

	if (me->query_temp("block_msg/all")>=1)
	me->add_temp("block_msg/all",-1);
    me->set_temp("disable_inputs",0);
	if (i < random(250))	// 250 enable move就100%安全
	{
		tell_object(me,HIR"\n\n陡然间一阵剧痛传遍浑身上下，你心中急叫道：完了．．．\n\n"NOR);
		me->die();	
		return 1;
	}

	REWARD_D->riddle_done(me,"明霞之阴",15,1);

	room=find_object(__DIR__"bottom1");
	if(!objectp(room)) 
        room = load_object(__DIR__"bottom1"); 

	tell_object(me,HIR"\n\n陡然间一阵剧痛传遍浑身上下，你心中急叫道：完了．．．\n\n"NOR);
	me->unconcious();
	me->move(room);
	message("vision",me->name()+"从上面掉下来，摔了个七荤八素，晕头转向。\n"NOR,environment(me),me);
    return 1;
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


