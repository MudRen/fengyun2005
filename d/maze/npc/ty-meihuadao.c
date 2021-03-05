#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("梅花盗",({"meihuadao","dao"}));
	set("title",MAG"千面花妖"NOR);
   	set("long","他，还是她？一张藏在粉色柔纱后的脸隐隐现出得意之色。顾盼之中，凶光乍现。。\n");
     	set("gender","女性");
     	set("age",20);
    	
    	set("class","huashan");
    	set("combat_exp",400000);  
    	    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	set_skill("perception",200);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
    	set("inquiry", ([
   	]));
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );  	
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
    	carry_object(__DIR__"obj/meihua_dart")->wield();
}

void 	init(){
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
     		this_object()->kill_ob(ob);
        }
}


void	die(){
	object cloth;
	object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        
	message_vision(MAG"
梅花盗眼中突现恐惧，身形陡变，双手疾挥，口中喷出一口血雾，洒在梅花上。 
一阵浓香的血雾升起，你胸中一阵难受，身形疾退。
梅花盗得意的咯咯笑着，笑声中已经无影无踪。"+HIR"

梅花千变，永生不死！ 


 
"HIC"血雾散尽，地上只有一方缀满梅花的纱巾。\n"NOR,this_object());

	cloth = new(__DIR__"obj/ty-meihua_ribbon");
	cloth->set("real",1);
	if (cloth) cloth ->move(environment(this_object()));
	
	if (me && REWARD_D->riddle_check(me,"桃花林探幽"))
		REWARD_D->riddle_set(me, "桃花林探幽",2);
	destruct(this_object());
}



void 	unconcious(){
	die();
}



int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()) {
		message_vision("人影闪动，梅花盗已无影无踪。。。。\n",this_object());
		destruct(this_object());
		return 1;
	}
	return ::heal_up() + 1;
}
