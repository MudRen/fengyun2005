// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李一摸", ({ "yimo" }) );
        set("gender", "男性" );
	set("title","一摸全");
        set("age", 52);
        set("long","一个疯疯癫癫的老头，不过他的＂一摸＂可神了．．．\n");
        set("combat_exp", 5000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
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
                        say( "李一摸说道：这位" + RANK_D->query_respect(ob)
                                + "，来让我摸一摸？\n");
                        break;
                case 1:
                        say( "李一摸笑道：这位" + RANK_D->query_respect(ob)
                                + "，来！让我再摸一把？\n");

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
	if(!arg) return notify_fail("李一摸道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("李一摸道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("李一摸道：＂那好象不是你的吧？＂\n");
	switch (random(9)){
		case 0: which = "int"; break;
		case 1: which = "con"; break;
		case 2: which = "per"; break;
	        case 3: which = "cor"; break;
	        case 4: which = "str"; break;
	        case 5: which = "fle"; break;
	        case 6: which = "agi"; break;
	        case 7: which = "tol"; break;
	        case 8: which = "dur"; break;
			}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) ;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost)
	return notify_fail("你的评价不够"+chinese_number(cost)+"点。\n");
	pet->add(which,1);
	pet->save();
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say 对吗！！下次再多摸几下！\n");
	return 1;
}
