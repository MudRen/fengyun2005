#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("小何",({"xiao he","xiaohe"}));
	set("title",HIR"快活林 杀手"NOR);
   	set("long","
小何漂亮得几乎已不像是个男人。高老大常说小何若是穿上女人的衣服，将
头发披下来，大多数男人都必定会被他勾去魂魄。尤其是他的皮肤，简直比
女人还细还白，很多人都不懂，像他这种在烈日风沙中长大的人，怎么会有
这么白的皮肤。他的眼睛却一直是那么萧索，那么忧郁。\n");

     	set("gender","男性");
     	set("group","khlr");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",5500000);  
    	set("attitude", "aggressive");
    	
    	set("inquiry", ([
 		"*":	"废话少说，拿命来。",
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,1,"/obj/weapon/","fighter_w","lefthand-sword",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

void die(){
	 object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
		
		} 
        
        if (me)
        if (REWARD_D->riddle_check(me,"菊园传奇")==3)
        	REWARD_D->riddle_set(me,"菊园传奇",4);
/*        
        if(me->query("marks/kuaihuo/夜见黑影"))
        {
                me->set("marks/kuaihuo/菊园刺客",1);
        }*/
        ::die();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",BLU"\n人影一闪又消失了。。。。\n" NOR, environment(),this_object() );
	environment()->set("xiaohe",1);
	destruct(this_object());
}