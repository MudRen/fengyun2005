inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("阿飞", ({ "afei", "fei" }) );
	set("gender", "男性" );
        set("title", "多情剑客");
        set("nickname", HIW "无情剑" NOR);
	
	set("age", 22);
	set("cor",200);
	
	set("class","assassin");
	set("long","
他的眉很浓，眼睛很大，薄薄的嘴唇紧紧抿成了一条线，挺直的鼻子使他的脸
看来更瘦削。这张脸使人很容易就会联想到花冈石，倔强，坚定，冷漠，对任
何事都漠不关心，甚至对他自己。但这却也是英俊的一张脸，虽然还太年轻了
些，还不成熟，但却已有种足够吸引人的魅力。\n");
        
        set("combat_exp", 6000000);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	set("NO_KILL","阿飞尚在牢笼之中，你根本无法碰到他 ！\n");
	set_temp("condition_type",WHT "<囚禁中>" NOR);
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	setup();
	
	carry_object("/obj/armor/cloth")->wear();
}



void	die(){
	object cloth;
	object me, owner;
	mapping data;
	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        
	message_vision(HIR"
阿飞苍白的脸色更加苍白，突然道：我不能死，我还要回去见仙儿。 

阿飞突然疾身后退，一个纵身，消失不见。\n\n"NOR,this_object());

	
	if (REWARD_D->riddle_check(me,"勇入少林"))
	if (!REWARD_D->check_m_success(me,"勇入少林"))
	{
		REWARD_D->riddle_done(me, "勇入少林",100, 1);
	
		data = ([
			"name":		"黄金塔：勇入少林",
			"target":	me,
			"att_1":	"con",
			"att_1c":	1,
			"mark":		1,
		]);
		REWARD_D->imbue_att(data);
	}
	
	if (me) me->set_temp("maze/sl_2",1);
	destruct(this_object());
}


int kill_him(object me){
	object ob = this_object();
	
	if (!me || !ob || environment(me)!= environment(ob) )
		return 1;
	ob->delete("NO_KILL");
	message_vision(HIW"
阿飞哼的一声，拔下铁笼上的一根铁条，冷冷看着你，一字一字道：谢-谢-你。 

阿飞突然哼了一声道：但你，曾经追杀过我的仙儿，谁-侮-辱-她，谁-就得死！ 
\n\n\n"NOR,me);
	ob->kill_ob(me);
	ob->carry_object(__DIR__"obj/sl-sword");
	ob->ccommand("wield sword");
	return 1;
}


void 	unconcious(){
	die();
}