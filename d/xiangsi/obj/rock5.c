#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("飞来石", ({ "rock","飞来石","灰岩"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块硕大的灰黑岩石，与周围的景色格格不入。\n据说这块岩石是天外飞来，已在这里摇摆了数百年。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

int do_pick(string arg)
{
	object bamboo,me = this_player();
	object room,*inv,who;
	int i,num;
	if ( !arg && arg != "rock" && arg != "飞来石" )
		return notify_fail("你要推什么？\n");
	message_vision(CYN"\n$N大喝一声，气沉丹田，双掌齐出，重重击在飞来石上。\n"NOR,me);
	if (me->query_str() < 40+random(80) || me->query("timer/moon_pushstone") + 900 > time())
	{
		me->set("timer/moon_pushstone",time());
		message_vision(CYN"只见飞来石左右摇摆，似是就要倾翻滚落，却又像不倒翁般半立起来，晃回原位。\n"NOR,me);
		return notify_fail("你不禁为造物之奇之巧惊叹。\n");
	}
	me->set("timer/moon_pushstone",time());
	message_vision(CYN"周遭积雪被$N掌风激荡翻飞而起，雪原上登时一片迷茫。\n隐约中你见到一个偌大的黑影一震，从山顶边笔直滚落。\n\n"RED"山下传来阵阵草木断折的声音与雷鸣般的碾压声．．．\n"NOR,me);
	environment()->set("no_stone",1);
	environment()->set("long", @LONG
攀上了相思雪峰的最高处，一片不甚宽广的雪地出现在你的眼前。银白色
的冰雪压覆在山顶，低头望去，山中飘游的云雾已尽皆在你脚下。雪地的边上
有一圈浅浅的凹槽，周围积雪松动，一条什么东西碾过的轨迹隐约可见，向山
下延伸而去。
LONG
        );
	if (!room=find_object("/d/xiangsi/liangjie"))
		room = load_object("/d/xiangsi/liangjie");
	tell_room(room,RED"\n一阵轰雷之声从山上传来，你愕然抬头，只见一块硕大的岩石正一路碾断草木，向你直压过来！\n\n"NOR);
	inv = all_inventory(room);
	i = random(sizeof(inv));
	who=inv[i];
	if (userp(who))	// 运气好到被压死了
	{
		if (random(who->query_skill("move")) < 100)	// move低的人容易有这种好运..
		{
			message_vision(CYN"$N吓得动弹不得，只见岩石一磕，冲$N直直撞去．．．\n"NOR,who);
			who->set_temp("last_damage_from","惨遭飞来横祸，被压成了一滩肉泥。\n");
			who->add_temp("block_msg/all",1);
			message_vision(CYN"\n转瞬之间$N就被压得又酥又软，糊成一滩。\n\n"NOR,who);
			who->delete("timer/lifesave");	// 落花流水一起去:p
			who->move("/obj/void");
			who->die();	
//			who->set_temp("block_msg/all",0);	// 尸骨无存．．

		if (who->query_temp("block_msg/all")>=1)
				who->add_temp("block_msg/all", -1);


			// 这是天命．．．
			// 天意，一切都是天意啊 *point norns *giggle
			if (!who->query("宿命B/相思_飞来"))
			{
				num = 1 + random(10);
				who->set("宿命B/相思_飞来",num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) 得到宿命B/相思_飞来 "+num+"。 %s \n",
					who->name(1), geteuid(who), ctime(time()) ));
			}
		}
		else
			message_vision(CYN"$N大惊之下提气纵起丈余，险险避过灭顶之灾。\n"NOR,who);
	}
	tell_room(room,RED"巨石激起一阵劲风，从你身边飞掠而过，吓得你心惊胆战，动弹不得。\n\n"NOR);
	destruct(this_object());
    return 1;
}

void init()
{
	add_action("do_pick","push");
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

