#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;

int do_shoot(object ob);

void create()
{
    	set_name("客商",({"trader"}));
	set("title","奄奄一息");

   	set("long","
他全身的皮肤都已被晒黑，嘴唇也晒裂了，眼睛半合半张，眼珠和眼白
却已分不清了，看来就像个灰蒙蒙的洞。。\n");
     	set("gender","男性");
    	set("age",32);
    	set("group","assassin"); 	
    	
    	set("kee",8000);
    	set("max_kee",8000);
    	set("eff_kee",8000);
    	set("NO_KILL","此人已经快断气了，你怎么忍心下手？\n");
	
    	set("combat_exp",2000000);  
    	
		set("chat_chance",1);
    	set("chat_msg",({
		"客商颤抖着，呻吟着，『水……水……』\n",
    	"客商挣扎着抬起手，向远方指了指，又拚命抓住头发，一张脸色因惊惧而扭
曲，身子也抖得更厉害。\n",

    	}) ); 
    	  	
    	set("death_msg",CYN"\n
$N全身都缩成一团，嘴里却疯狂般大叫起来，嘶声叫道：“你杀了我吧！
没关系，反正你们也活不长的，我在鬼门关上等着你，再和你算帐。”\n"NOR);  	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
 	
		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_u","wolf-strike",1);
		setup();    
}

void init(){
	::init();
	add_action("do_look", "look");
}

int do_look(string arg) {
	if(arg == "trader"){
		write("
他全身的皮肤都已被晒黑，嘴唇也晒裂了，眼睛半合半张，眼珠和眼白
却已分不清了，看来就像个灰蒙蒙的洞。。
他看起来约三十多岁。
他风度翩翩，如玉树临风。\n");
		write("他"CYN"让人觉得气质文弱"NOR"，武功看起来好象"BLU"毫不足虑"NOR"，出手似乎很轻。
他"HIR"流血不止，动作散乱，已经在走下坡路了"NOR"。
他赤身裸体。\n");
		return 1;
	}
	return 0;
}


int accept_object(object who, object ob)
{
    	object tietong;
    	if (ob->query("liquid/type")=="alcohol" || ob->query("liquid/type")=="water") {
        	if ((int)ob->query("liquid/remaining") == 0) {
            		command("shake");
            		command("say 『水……水……』");
            		return 0;
        	}
            	else {
	            	command("smile");
	            	command("say 多谢!");
	            	ob->move(this_object());
	            	command("drink "+ob->query("id"));
	            	ob->move(this_player());
	            	ob->stop_busy();
	            	if (!tietong=present("box",this_object())){
	            		tietong= new(__DIR__"obj/tietong");
	            		tietong->move(this_object());
	            	}
	            	this_object()->set("name","刺客");
	            	set("chat_chance",0);
	            	delete("NO_KILL");
	            	do_shoot(who);
	            	kill_ob(who);
	            	return 1;
        	}
    	}
    	else 
    		return 0;
}

int do_shoot(object ob)
{
	
	object me;
//	string where;
	int dp, damage;
	
	me = this_object();
		
	if (!present(ob,environment(me)))
		return notify_fail("这儿没这个人。\n");
		
	message_vision(HIB"说时迟那时快，突变骤生，$N一扬手，十几道乌光从指缝中向$n飞去！！！\n"NOR,me,ob);
    	    	    
    	if (ob->query_skill("perception")/10>random(22)) {
    		message_vision("$N听风辨形，居然在间不容发之际躲过了这暗器！\n\n",ob);
    	}else {
		message_vision(HIB"银光打在$N身上，一闪就消失了。\n\n"NOR,ob);
		dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
		damage=600000-dp;
		damage/=100;
		if (damage<0) damage=0;
		ob->receive_wound("kee",damage,me);    
		ob->receive_wound("gin",damage,me);    
		ob->receive_wound("sen",damage,me);    
	}	
    		
    	COMBAT_D->report_status(ob);                                         
    	ob->kill_ob(me); 
    	set("used",1);
    	me->start_busy(3);
    	if (ob->query("combat_exp")< 20000)
    		command("say 上当了！是大米！！！");
    		command("faint trader");
    	return 1;
}


void die(){
	environment(this_object())->set("long", @LONG
沙丘并不大，转过沙丘，就瞧见一个人，这个简直已不大像是人，而像是一只
被架在火上，快被烤焦了的羊，他赤裸裸地被人钉在地上，手腕。足踝，和面额上，
都绑着牛皮，牛皮本来是湿的，被太阳晒乾後，就越来越紧，直嵌入肉里。现在他
已经彻彻底底地死了，再没有一丝生气。
LONG
        );
        ::die();
}