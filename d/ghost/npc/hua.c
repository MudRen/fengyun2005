#include <ansi.h>
inherit NPC;

void create()
{
        set_name("花寡妇", ({ "hua gua fu", "hua", "gua fu" }) );
        set("gender", "女性");
        set("per", 24);
	set("str", 40);
        set("age", 35);
        set("class", "ghost");
        create_family("幽灵山庄", 2, "弟子");
        set("combat_exp", 200000);
        set("long",
		"她长得并不美，颧骨太高了些，嘴也太大了些。
但她无疑是个很特别的女人，大多数男人只要看她一眼，
立刻就会被她吸引住。\n"
	);
	set("no_arrest",1);
	set_skill("unarmed", 100);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("whip", 100);
        set_skill("snowwhip", 100);
	map_skill("whip", "snowwhip");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object		me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		add_action("do_sleep", "sleep");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
	remove_call_out("greeting");
	if(me && environment(me) == environment(this_object())) {
		message_vision(HIM "\n$N倒在床上，用一双迷迷蒙蒙的眼睛打量着$n" +
				"，道：上床呀，为什么还不上床？\n"NOR, this_object(), me);
		call_out("greeting", 10, me);
	}
	return 1;
}

int do_sleep(string arg)
{
	object *inv;
	int i;

	if(!arg || arg != "hua gua fu") return 0;
	remove_call_out("greeting");
	this_player()->start_busy(5);
	this_player()->ccommand("remove all");
	message_vision(HIM "\n$N迫不极耐的脱下衣服，跳上床去，一把抱住了$n\n．．．．．．\n．．．\n"NOR, this_player(), this_object());
	call_out("do_smoke", 5, this_player());
	return 1;
}

int do_smoke(object me)
{
	if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
		return 1;
	say(HIR "\n窗隙里慢慢伸进了一只吸管，\n"NOR);
	call_out("do_smoke1", 2, me);
	return 1;
}

int do_smoke1(object me)
{
	if (!objectp(me) || me->is_ghost() || environment(me)!=environment(this_object()))
		return 1;
	say(BLU "\n从吸管里喷出一股暗紫色的浓烟。\n"NOR);
	me->unconcious();
	me->move(AREA_GHOST"dijiao2");
	return 1;
}
