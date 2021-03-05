// 守门师兄--- by silencer@fy4 workgroup 02/2003

#define CHAMPION_FILE "/obj/npc/champion.o"
#include <ansi.h>

inherit NPC;

void unloadall(object me);
void changeshape(object winner);
void fight_skill_setup();
int brag();
int do_set_skill(string arg);
void smart_fight();

void create()
{
	string info,name,id,file,c_class;
	
        set_name( "大师兄" , ({ "brother" }) );
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        	set_name( name, ({ id + "NPC"}) );
        	delete("env");
        	delete("marry");
        	set("attitude", "friendly");
        	unloadall(this_object());
        	c_class = F_MASTER->query_chinese_class(query("class"));
        	set("title", HIR ""+ c_class +"  掌门弟子"NOR);   
        	heal_up();
        	clear_all_condition();
		set("chat_chance_combat", 100);
        	set("chat_msg_combat", ({
	        	(: smart_fight() :),    
        	}) );
	}
	set("chat_chance", 1);
        set("chat_msg", ({
                (: brag :),
        }) );
	
	setup();	
	carry_object("/obj/armor/cloth")->wear();
		
}

//	玩家数据复制。
void changeshape( object winner)
{
	string winner_file;
	string name,id, temp1, c_class;
	object target_weapon, newweapon;
	int num1;
	
	if(!stringp(winner_file = winner->query_save_file()))
		return;
        c_class = F_MASTER->query_chinese_class(winner->query("class"));
        CHANNEL_D->do_sys_channel(
        	"info",
        	sprintf( "%s勇夺『" + c_class + "』掌门弟子之位！\n",winner->name(1)));

	seteuid(ROOT_UID);
	write_file(CHAMPION_FILE,sprintf("%s %s %s", winner_file,winner->query("id"),winner->query("name")),1);
	seteuid(getuid());
	restore_object(winner_file);

	name = winner->query("name");
	id = winner->query("id");
	set_name( name, ({ id+"NPC" }) );
	delete("env");				// No more wimpy.
	delete("marry");  			// No more learning.
	reset_action();
	
	unloadall(this_object());	
    	set("title", HIR ""+ c_class +"  掌门弟子"NOR);   
    	//  复制武器
    	if(target_weapon = winner->query_temp("weapon"))	{
		sscanf(file_name(target_weapon),"%s#%d",temp1,num1);
		newweapon=new(temp1);
		newweapon->set("nodrop_weapon",1);  	// We don't want his weapon to be dropped/cloned.
		newweapon->move(this_object());
		newweapon->wield();
	}
	heal_up();
        clear_all_condition();
    	set("chat_chance", 1);
        set("chat_msg", ({
                (: brag :),
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: smart_fight() :),    
        }) );
    	setup();
    	return ;
}


//	去除所有携带物品
void unloadall(object me)
{
        int i;
        object *inv, armor;
	inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
              destruct(inv[i]);
        seteuid(getuid());
        armor = new("/obj/armor/cloth");
        armor->move(me);
        armor->wear();
        return ;
}

int brag()
{
        CHANNEL_D->do_channel(this_object(), 
        		"bangtalk", 
        		"师弟师妹们努力啊，振兴师门的重任就在咱们身上！\n");
        return 1;
}

void lose_enemy(object winner)
{
	if (winner->query("name") == query("name")) {
    		message_vision(CYN"$N苦笑着说：你就是我，我就是你，还比什么。\n"NOR,this_object());
    		return;
    	}
	message_vision(CYN"$N说：唉，看来我只能让贤了。。。。\n"NOR,this_object());
	call_out("changeshape",2,winner);
	return;
}

void win_enemy(object loser)
{
    	string peer;
    	if (loser->query("name") == query("name")) {
    		message_vision(CYN"$N淡淡一笑说：青出于蓝而胜于蓝。\n"NOR,this_object());
    		return;
    	}
    	
    	peer = query("family/enter_time") > loser->query("family/enter_time") ? 
    		(loser->query("gender") == "男性" ? "师弟": "师妹")
    		: (loser->query("gender") == "男性" ? "师兄": "师姐");
    	
    	message_vision(CYN"$N淡淡一笑说：" + peer+ "还要努力呀！\n"NOR, this_object());
    	return;
}

int accept_fight(object me){
	if (me->query("class") != query("class")) {
		message_vision(CYN"$N摇摇头说：在下只与本门弟子切磋武艺。\n"NOR,this_object());
		return 0;
	}
	if (is_fighting() || is_busy()) {
        	message_vision(CYN"$N一边招架一边说：让我先解决了眼前这个再说！\n"NOR,this_object());
        	return 0;
        }
        me->save();
        heal_up();	
	message_vision(CYN"$N说：好，咱们点到为止！！！\n"NOR,this_object());
	return 1;
}

void die()
{
        object ob;
        string c_class, peer;
        ob = query_temp("last_damage_from"); 
        if(!ob) return;
	if (ob->query("id") == query("id")+"NPC")	return;
	c_class = F_MASTER->query_chinese_class(query("class"));
	if (ob->query("class")!= query("class")) {
	        CHANNEL_D->do_sys_channel(
			"info",
        		sprintf( "%s攻入『" + c_class + "』，击毙其掌门弟子"+name()+"！\n",ob->name(1)));
        } else {
	        peer = query("family/enter_time") > ob->query("family/enter_time") ? 
	    		(ob->query("gender") == "男性" ? "师弟": "师妹")
	    		: (ob->query("gender") == "男性" ? "师兄": "师姐");
		CHANNEL_D->do_channel(this_object(),
				"bangtalk",
	        		sprintf( "%s比武中失手击死掌门"+peer+name()+"！\n",ob->name(1)));
	}
	message_vision("$N死了。\n",this_object());
        destruct(this_object());
        return;
}


int heal_up()
{
    	int mgin,mkee,msen;
    	mgin=(int)query("max_gin");
    	mkee=(int)query("max_kee");
    	msen=(int)query("max_sen");
    	set("eff_kee",mkee);
    	set("eff_gin",mgin);
    	set("eff_sen",msen);
    	set("gin",mgin);
    	set("kee",mkee);
    	set("sen",msen);
    	::heal_up();
    	return 1;
}


int do_killing(string arg)
{
    	object player, victim;
    	string id,id_class;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
       		if(victim == this_object())
        	{
            		remove_all_enemy();
            		command ("say 有敌来犯，快快护卫师门！");
/*			CHANNEL_D->do_channel(this_object(), 
        			"chat",
        			sprintf( "%s勇夺『" + c_class + "』掌门弟子之位! ! ! \n",winner->name(1)));*/
            		return 0;
        	} 
    	}
    	return 0;
}

void init()
{
	::init();
	add_action("do_killing", "kill");
	add_action("do_set_skill","setup");
						
}
		
void smart_fight (){
	
	int num, pfm_num;
	string pfm_act;
	
	if (!query("pfm_num"))	return;
	if (query("perform_chance")) num = query("perform_chance");
		else num = 100;
	
	if (random(100)<num) {
		pfm_num = random(query("pfm_num"))+1;
		pfm_act = query("pfm"+pfm_num);
		perform_action(pfm_act);
	}
        return;        
}
	

int do_set_skill(string arg){

	string type, value;
	object me, weapon1;
	int num;
	me = this_player();
	
	if (!arg) {
		write("	

格式：	setup pfm1 技能名\特殊技能名
	setup weapon 武器名
举例    setup pfm1 unarmed\luori 就是让NPC perform luori
	setup weapon blade 就是让NPC wield blade
	setup pfm2 none	就是清除 pfm2。
	最多允许 setup 三个 pfm1, pfm2, pfm3。
注意事项：
	1。如果定义的perform无效，（打错字母，门派不对或武器不对等）则不起作用。
	2。必须从pfm1开始定义，可以只定义pfm1，但是不能只定义pfm3。
	3。如果你想去除一个perform 1，请使用setup pfm1 none 。
	4。只能由掌门弟子本人设定。		
	5。武器只能是一般武器如blade，sword，hammer等
		\n");

		return 1;
	}
	
	if (me->query("name")!= query("name") && !wizardp(me))
		return notify_fail("你不是掌门弟子，没有权利设定perform。\n");
		
	sscanf(arg, "%s %s", type,value);
	
	if (type == "weapon") {
		if (value == "blade" || value == "sword" || value =="staff"
			|| value == "dagger" || value == "hammer" || value == "whip"
			|| value == "spear" || value =="dart" || value == "axe") {
				command("unwield all");
				unloadall(this_object());
				weapon1 = new("obj/weapon/"+value);
				if (weapon1) {
					if (weapon1->move(this_object()))
						command("wield all");
				return 1;
				} else 
					return notify_fail("武器种类错误。\n");
		} else
			return notify_fail("武器种类错误。\n");
		
	}
	
	if (type != "pfm1" && type !="pfm2" && type!="pfm3")
		return notify_fail("格式错误，请用setup来查看格式。\n");
		
	if (value == "none") {
		delete(type);
		return 1;
	}	
	switch (type) {
		case "pfm1": set("pfm1",value); break;
		case "pfm2": set("pfm2",value); break;
		case "pfm3": set("pfm3",value);
	}
	write(value+"已经设定在"+ type +"。\n");
	num = 0;
	if (query("pfm1")) num++;
	if (query("pfm2")) num++;
	if (query("pfm3")) num++;
	set("pfm_num",num);
	return 1;
}

		