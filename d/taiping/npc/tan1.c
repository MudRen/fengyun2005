#include <ansi.h>
#include <command.h>
inherit SMART_NPC;
inherit __DIR__"timeshift";

int red_stone();
void throw_away(object ob);

void create()
{

	set_name("谭天龙",({"tan tianlong","tan"}));
    	set("title",YEL"谭门三霸天 老大"NOR);
    	set("long", "
谭门三霸天当然姓谭。也许他们并不是北派谭腿的嫡系，可是他们自己要这么说，
就没有人敢怀疑，也没有人否认。拼了十三年命，经过了大小两百多次浴血苦战，
“谭门三霸天”确实已在江湖中稳稳站住了脚，想推倒他们的人，大多数已被他
们一脚踢死。\n");

	set("age",40);
	set("combat_exp", 6500000);
	set("class","swordsman");        	
	set("attitude","friendly");
	set("group","tan");
	
	set("reward_npc",5);
		
	set("day_room","/d/taiping/house1");
	set("dinner_room","/d/taiping/laodian");
	set("shift/dinner_leave","$N一边往外走一边骂着说：“嘴里快淡出个鸟来了！”\n");
	set("shift/dinner_arrive","$N走过来一拍桌子：“快，上菜。”\n");
	set("shift/after_dinner","$N抹了抹嘴，心满意足打着饱嗝走出了门。\n");
	set("shift/back_dinner","$N晃荡晃荡走了过来。\n");
	
	set("death_msg",CYN"\n$N说：老二老三会为我报仇的。啊啊啊。。。 \n"NOR);		
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	20: 	(: red_stone() :),
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps",1);
		
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object(__DIR__"obj/lan_cloth1")->wear();

}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object *inv;
	string my_position;
	
	if( !ob || environment(ob) != environment()) return;
	
	my_position=file_name(environment(this_object()));
	if(my_position==this_object()->query("day_room")) {
		command("say 谁让你进来的？滚出去！");
		call_out("throw_away",10,ob);
	}
	remove_call_out("shifting");
	call_out("shifting", 1, this_object());

}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	this_object()->kill_ob(ob);
	kill_ob(this_object());
}

int red_stone() {
	object me,ob, stone;
	me=this_player();
	ob=this_object();
	if (file_name(environment(ob))!= AREA_TAIPING"laodian") return 1;
	message_vision(WHT"\n$N突然怒吼，身子凌空扑起，双腿连环踢出。这已不是正宗的谭腿，威力却远
比谭腿更大，正是他纵横江湖的成名绝技。\n"NOR, ob);
        message_vision(WHT"谁知$N身子刚扑起，就听见“嚓，嚓”两声响，接着一声惨呼。\n"NOR,ob);
        message_vision(WHT"$N倒下去时，两条腿的膝盖关节处已碎裂。\n"NOR,ob);
        stone=new(AREA_TAIPING"npc/obj/redstone");
        if (stone) stone->move(ob);
        die();
        return 1;
}	

