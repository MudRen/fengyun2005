// hell_guard.c

#include <ansi.h>

inherit NPC;

void backattack();
void smart_fight();

string *poet = ({
"　　与生俱来人中首，唯我与天同齐寿。
　　双脚踢翻尘世浪，一肩担尽古今愁。",
"　　真神真圣亦真仙，通儒信道是通贤。
　　脑中玄机用不尽，统辖文武半边天。",
"　　白发三千横世态，玉骨冰心纵苍穹。
　　风节自古如残照，青袍一舞笑人庸。",
"　　蜉蝣天地静观心，青衣染尘出钟林。
　　吾独南行顺天意，疏竹轻纱掩人虚。",
"　　难定纷纷甲子年，千魔荡荡白阳天。
　　苍天旨意奉书命，诸子虔诚扶道颠。"});

void create()
{
	string *order = ({YEL"上清",MAG"太清",WHT"玉清"});

	set_name((order[random(3)]) + "道人"NOR, ({ "sanqing taoist" }) );
	set("long", "这是三清大殿所供的尊道化身。\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	
	set("combat_exp", 100000);
	set("chat_msg_combat", ({
        	 (: smart_fight() :),

	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);
	set_skill("hunting-fork",70);
	set_skill("notracesnow",70);
	map_skill("dodge","notracesnow");
	map_skill("fork","hunting-fork");
	map_skill("parry","hunting-fork");
	setup();

	carry_object(__DIR__"obj/golden_armor",
    		([	"name"	:	CYN"仙家道袍"NOR,
			"id":"cloth",
    			"value"	:	0,
				"long"	: "",
			"armor_prop/armor"	: 20, ])
    		)->wear();

	carry_object(__DIR__"obj/golden_sword",
			([	"name"	:	WHT"白玉拂尘"NOR,
				"id"	: "fuchen",
				"long"	: "",
    				"value"	:	0,	])
		)->wield();
}



int heal_up()
{
	if( environment() && !is_fighting() && !query("is_leaving")) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner,*pros;
	if (environment())
	message("vision",
		HIY + name() + "化作一道青烟消失了。\n\n" NOR, environment(),		this_object() );
    if(objectp(owner=this_object()->query("possessed")))
    {
            if (owner->query_temp("max_guard")>0)
            	owner->add_temp("max_guard",-1);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}

void init()
{
        ::init();
        add_action("do_dismiss","dismiss");	
}  

int do_dismiss(string arg)
{
        object who,obj;
        if(!arg) return 0;
        if(!obj=present(arg,environment()))
        	return 0;
        if(obj!=this_object()) return 0;
       
       	who=this_player(); 
                
        if(who!=obj->query("possessed")) 
        	return 0;

		if (obj->is_fighting())
        {
        	tell_object(who,"此召唤兽正在战斗中，无法驱散。\n");	
        	return 1;
        }
        
        if (query("is_leaving")) {
        	tell_object(who,"你已经使用了此法术了。\n");
        	return 1;
        }
        	
        if(who->query("sen")<300)
        {
        	tell_object(who,"此诀耗费需要300点心神。\n");
            return 1;
        }
        who->receive_damage("sen",300);
        message_vision(HIB"$N喃喃念个“疾”字，一缕黑气，细若烟尘，从指端点向$n。\n"NOR,who,obj);
        set("is_leaving",1);
        remove_call_out("leave");
        call_out("leave",1);
        return 1;
} 


void smart_fight()
{
	object me = this_object();
	object owner = this_object()->query("possessed");
	int i,type,duration,amount;
	string typ,msg;

	if (!owner)
		return;

	if (is_busy())
		return;	

	type=owner->query_temp("last_sqpfm_used");

	switch (type)
	{
		case 2:
			typ = "drainerbolt";
			break;
		case 1:
			typ = "feeblebolt";
			break;
		case 3:
			typ = "netherbolt";
			break;
		default: 
			typ = "netherbolt";
	}


	ccommand("cast "+typ);
	return;
}

void invocation(object who, int level)
{
	int i, bonus_skill;
	object *enemy,*pros;

	int exp = 20000 + level/8*level/2*level/2 *33/20;

	if (exp > who->query("combat_exp"))
		exp = who->query("combat_exp");
		
	exp = exp/100 * (100 + F_ABILITY->check_ability(who,"shangjun_add"));
	
	set("combat_exp", exp);
	set("level", F_LEVEL->get_level(query("combat_exp")));

	set("class","taoist");

	set_skill("sword", who->query_skill("sword",1));
	set_skill("parry", who->query_skill("parry",1));
	set_skill("dodge", who->query_skill("dodge",1));
	set_skill("move", who->query_skill("move",1));
	set_skill("spells", who->query_skill("spells",1));
	set_skill("force", who->query_skill("force",1));
	set_skill("unarmed", who->query_skill("unarmed",1));
	set_skill("scratching", who->query_skill("scratching",1));

	set_skill("notracesnow",who->query_skill("notracesnow",1)+1);
	set_skill("snowshade-sword",who->query_skill("snowshade-sword",1)+1);
	set_skill("necromancy",who->query_skill("necromancy",1)+1);
	set_skill("gouyee",who->query_skill("gouyee",1)+1);
	set_skill("tenderzhi",who->query_skill("tenderzhi",1)+1);
	set_skill("scratmancy",who->query_skill("scratmancy",1)+1);

	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("spells","necromancy");
	map_skill("force","gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("parry","hunting-fork");
	map_skill("sword","snowshade-sword");
	map_skill("scratching","scratmancy");

	set("chat_chance_combat",level/6+random(level/6));
	"/feature/nada"->reset_npc(this_object());
	set("max_kee",who->query("max_kee")*5/10);
	set("max_gin",who->query("max_gin")*5/10);
	set("max_sen",who->query("max_sen")*5/10);
	set("force_factor",0);
	set("str",level/10);

	if (who->query_skill("taoism",1)>200) 
		add("resistance/kee", (who->query_skill("taoism",1)-200)/2);
			
	full_me();
	
	message("vision",
		CYN "\n
天庭上突而钟鼓齐鸣，来了一位道人，打扮得与三清神像别无二致，手持
一柄白玉拂尘，大呼曰：“这位道兄！吾来助你一臂之力！
说罢吟道：
"+poet[random(5)]+"    吾乃"+name()+CYN"是也！\n" NOR,
		environment(who), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else {
				enemy[i]->kill_ob(this_object());
				enemy[i]->kill_ob(who);
			}	
		}
	}
	set_leader(who);
	set("possessed",who);
	reset_action();
}


void unconcious() {
	die();
}

void die()
{
	object *pros,owner,*enemy;
	int i;
        if(objectp(owner=this_object()->query("possessed")))
        {
            if (owner->query_temp("max_guard")>0)
              	owner->add_temp("max_guard",-1);
			
			// backfire a little bit hate to prevent chain pets.
			enemy = query_enemy();
			if (enemy && sizeof(enemy)>0){
				for (i=0;i<sizeof(enemy);i++){
					if (!userp(enemy[i]))
						enemy[i]->add_hate(owner,enemy[i]->query_hate(this_object()));
				}
			}
	}                
    message_vision("\n$N化作一道青烟消失了。\n\n", this_object());
	destruct(this_object());
}



void heart_beat()
{
	object leader;
	
	::heart_beat();
    
    if(!this_object()) 		return;
	
	if(query_temp("is_unconcious")||is_busy())
		return ;
	if(query("possessed"))
	{
		leader=query("possessed");
		if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N匆匆离去。\n",this_object());
			this_object()->move(environment(leader));
			message_vision("$N飞了过来。\n",this_object());
			delete("leave_room");
		}
	}
	
	else
	{
		if(!query("leave_room"))
			set("leave_room",1);
		else
			add("leave_room",1);
		if(query("leave_room")==5)
			leave();
	}
}



/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
