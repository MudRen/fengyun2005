inherit NPC;
#include <ansi.h>
int do_hint();

void create()
{
		set_name("阿飞", ({ "afei", "fei" }) );
		set("gender", "男性" );
        set("title", HIG "情为何物" NOR);
		set("age", 20);
		set("class","assassin");
		set("per", 30);
		set("long","天下无敌－－－阿飞\n");
	        
        set("reward_npc", 1);
		set("difficulty", 30);
                
        set("inquiry", ([
	         "梅花盗" : (: do_hint :),
		]) );
        
        set("combat_exp", 10000000);
        set("score", 90000);
        set("fy41/jq_sharenruma",1);
       	set_temp("apply/haste",300);         
        
        set_skill("sword", 400);
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("sharen-sword", 250);
		set_skill("lefthand-sword",300);
		set_skill("jinhong-steps",250);
		set_skill("unarmed",400);
		set_skill("flame-strike",200);
		set_skill("move",200);
		
		map_skill("unarmed","flame-strike");
		map_skill("sword", "sharen-sword");
		map_skill("parry","lefthand-sword");
		map_skill("dodge","jinhong-steps");
		map_skill("move","jinhong-steps");
	        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
	
		setup();
		carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}

int do_hint(){
	message_vision("阿飞皱了皱眉头说：这梅花盗劫了何人，你想让我去救谁？（rescue）\n",this_object());
	return 1;
}

int accept_fight(object me)
{
        command("grin");
        command("say 我的剑是用来杀人的，不是用来比划着玩的。");
        return 0;
}

void init()
{
	add_action("do_killing", "kill");
	add_action("do_rescue", "rescue");
	::init();
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "林仙儿")
		{
		message_vision("$N冷笑一声道：我看你活得太长了。\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}



int do_rescue(string arg)
{
	
	object player, victim, room;
	string name;
	player = this_player();
	if( !arg) return notify_fail("你想让阿飞救谁？\n");
	victim = find_player(arg);
	if( !objectp(victim)) return notify_fail("没有这个人啊？\n");
	message_vision("\n$N张张惶惶地对阿飞喊：飞剑客，不好了！" + victim->name() + "被梅花盗劫走了。\n\n", player);
	if( !victim->query_temp("marks/meihuadao") )
		return notify_fail("阿飞皱皱眉头说，“这个人被梅花盗劫走了？是谣传吧？”\n");

	message_vision("\n$N关切地看了林仙儿一眼，对$n说：你先去荒园好好搜寻一下，我马上就到。\n", this_object(),player);
	player->set_temp("afei_on_the_way", 1);
	return 1;
}

int kick_player(object ob)
{
    	if( ob->query("gender") == "女性")
         	call_out("do_kick", random(20)+10,ob);
    	else
         	call_out("do_kick", random(10)+5,ob);
    	if(!random(8))
    		ccommand("heihei "+ob->query("id"));
    	else
    		command("heng");
    	return 1;
}


void do_kick(object ob)
{
    	object room;
    	if(environment(ob) == environment(this_object()))
    	{
        
        	message_vision(CYN"$N磨了磨牙。\n"NOR, this_object());
        	message_vision(CYN"$N恶狠狠地瞪了$n一眼。\n"NOR, this_object(), ob);
	        message_vision(HIB"\n阿飞的脚似乎动了动，$N只觉得后面一疼，自不眠阁顶乘云驾雾般飞了出去．．．\n\n"NOR,ob);
        	room=find_object(AREA_QIANJIN"boat3");
        	if(!objectp(room))
             		room=load_object(AREA_QIANJIN"boat3");
        	ob->move(room);
        	message_vision(BLU"\n只见一条身影破窗而出，$N好似熟透了的柿子一样坠落，随着水花四溅的\n「扑通」一声落入湖中，惊得船上红男绿女大呼小叫起来。\n\n"MAG"$N湿淋淋的从湖里爬了起来．．．\n\n"NOR,ob);
        	ob->receive_damage("kee",100);
        	ob->set_temp("last_damage_from","莫名其妙地死在千金楼里。\n");
       		ccommand("emote 满意的拍了拍手。");
    	}
}

