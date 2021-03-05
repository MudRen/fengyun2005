inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("上官金虹", ({ "shangguan jinhong","shangguan"}) );
    	set("nickname", RED"龙凤双环"NOR);
    	set("gender", "男性" );
    	set("class", "assassin");
    	set("long","
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出
一丝得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松
弛，一个人的精神若松弛，就容易造成错误。\n");

       	set("age", 44);
    	set("attitude","aggressive");

	set("zombie-killer",1);
	set_temp("apply/haste",300);
    	set("combat_exp", 8000000);
    	
    	set("officer-killer",1);		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
    	    
	auto_npc_setup("liaoyin",350,220,0,"/obj/weapon/","fighter_w","longfenghuan1",2);
	setup();
	
    	carry_object(AREA_FY"npc/obj/yellow_suit")->wear();
    	carry_object(AREA_FY"npc/obj/hat")->wear();
    	carry_object(AREA_FY"npc/obj/longfenghuan")->wield();
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
	
	object *inv, lin;
	string my_position;
	if( !ob || environment(ob) != environment()) return;
	message_vision("
上官金虹漠然的眸子突然燃起火来，微微笑道：不错，终于有人上到这里了！
不错，不错， 龙凤环自从饮了孙老头的鲜血后，已经很久没有血来喂饱它了。\n"NOR,ob);
}

void	die(){
	object cloth;
	object me, owner;
	object *inv;
	int i;
	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if (!query("reincar")) {
        	message_vision(CYN"
赤虚子冷冷地笑道：死人才是最好的武器，上官，你死了，这天下，这金塔，
这女人，就全属于我了。 

赤虚子凌空虚点，几道灵符“啪，啪。。”地贴到上官的天灵盖和心口处。 
“起。。。。”赤虚子念念有词。 

半死的上官金虹僵直的突然立了起来。 \n\n"NOR + HIR"

上官金虹瞪着血红的双眼向你扑来，声势更盛！\n\n"NOR, this_object());
		set("combat_exp",12000000);
		set("reincar",1);
		set("kee",query("max_kee"));
		set("gin",query("max_gin"));
		set("sen",query("max_sen"));
		set("eff_kee",query("max_kee"));
		set("eff_gin",query("max_gin"));
		set("eff_sen",query("max_sen"));
		set("resistance/gin",50);
		set("resistance/sen",50);
		set("resistance/kee",50);
		
		set("title",HIR"活死人"NOR);
		inv = all_inventory(environment());
		for (i=0;i<sizeof(inv);i++)
		{
			if (userp(inv[i])) kill_ob(inv[i]);	
		}
		return ;
	}
	if (me)
	if (present("meihuadao", environment()) && present("chi xu",environment()) )
		environment()->event1(me,0);
	
	// 这里应该让上官掉一些好东西了。。。。。有待加入。
	::die();
}

void 	unconcious(){
	die();
}
