// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("高人", ({ "gaoren" }) );
        set("gender", "男性" );
	set("title","半仙兽");
        set("age", 32);
        set("long","一个得半道的老道士，对改善动物的体质别有妙技。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "高人说道：这位" + RANK_D->query_respect(ob)
                                + "，来陪我聊一聊？\n");
                        break;
                case 1:
                        say( "高人笑道：这不，生意来了！\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
	string which;
        me = this_player();
        if(me->is_busy())
        	return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("高人道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("高人道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
		return notify_fail("高人道：＂那好象不是你的吧？＂\n");
	switch (random(3)){
		case 0: which = "max_gin"; break;
		case 1: which = "max_kee"; break;
		case 2: which = "max_sen"; break;
	}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) / 10;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost)
	return notify_fail("你的评价不够"+chinese_number(cost)+"点。\n");
	pet->add(which,10);
	pet->save();
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say 这就得了！\n");
	return 1;
}
