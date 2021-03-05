inherit NPC;
#include <ansi.h>

int guardd();
int failit();
int dont();
int dontt();

void create()
{
        set_name("百晓生", ({ "bai xiaosheng", "bai"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是当今天下武林的第一才子，他将天下所有顶尖英雄都列于
他的兵器谱上。\n");
        set("combat_exp", 7000000);
        set("attitude", "friendly");

    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("literate", 200);
    	set_skill("unarmed",200);
    	set_skill("puti-steps",200);
    	set_skill("yizhichan",200);
    	set_skill("buddhism",250);
    	set_skill("chanting",200);
    	set_skill("xiaochengforce",200);
    	set_skill("staff",200);
    	set_skill("parry",200);
    
    	map_skill("parry","yiyangzhi");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "yizhichan");
    	map_skill("move", "puti-steps");
    	
    	

	    	set("inquiry", ([
        	"弧形长刀": (: dont :),
        	"拜": (: dontt :),
        	"拜拜": (: dontt :),
        	"拜．．．拜．．．": (: dontt :),
        	"拜．．．": (: dontt :),
    	]));

		set("intellgent",1);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"道：什么？你也想让我把你列入兵器谱！！？？\n",
                name()+"道：我的兵器谱恐怕要写出几千卷才能排上你。\n",
        }) );
	
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int dont()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 8)  
	{
		ccommand("dunno "+me->query("id"));
		return 1;
	}
	ccommand("emote 沉吟道：弧形双手长刀．．．");
	ccommand("say 那不是"YEL"东瀛浪人"CYN"所用兵器么？莫非是他．．可是他为什么要．．？");	 // 百晓生指高猛，不过误导ppl去找tianfeng
	REWARD_D->riddle_set(me,"多事之秋",9);
	return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/



int dontt()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"多事之秋") != 12
		 && REWARD_D->riddle_check(me,"多事之秋") != 13)  
	{
		ccommand("heihei "+me->query("id"));
		return 1;
	}
	ccommand("emote 脸色一变，冷笑道：好，是你自己送死，须怪不得我！");
	REWARD_D->riddle_set(me,"多事之秋",13);
	kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}

void killed_enemy(object who)
{
    command("heng");
    command("say 我佛云雷霆手段，菩萨心肠，今日你须怨不得我！");
}

void unconcious()
{
	die();
}

void die()
{
//	int i;
	object killer, owner,me;
	object room;
	mapping data;
	
	room = environment();
	if(objectp(killer = query_temp("last_damage_from")))
	{
		if(owner=killer->query("possessed"))
			killer = owner;

			me=killer;

		if(REWARD_D->riddle_check(me,"多事之秋") != 13 
			&& !REWARD_D->check_m_success(me,"多事之秋"))
		{
			// rob的?
			::die();
			return ;
		}

		message_vision(HIR"\n$N目睚俱裂，大喝道：好，好！\n$N长身而起，集全身功力向$n扑去！\n"NOR,this_object(),killer);

		killer->set("annie/demon_gao",1);
		
		if (random(killer->query_skill("move",1)) > 100)
		{
			message_vision("$n身随意转，闪在一旁，$N毕生功力击于墙上，竟将墙壁轰出一个大洞！\n\n",this_object(),killer);
		}
		else
		{
			message_vision(CYN"$n闪躲不及，被$N毕生功力所聚的一掌印在胸口，顿时如断线风筝般飞出！\n$n飞到六丈开外，猛然撞在墙上，竟将墙壁撞出一个大洞！\n"NOR,this_object(),killer);
			killer->receive_wound("kee",(400-random(killer->query_skill("parry",1)))*20,this_object());
			COMBAT_D->report_status(killer);
		}
        
        REWARD_D->riddle_done(me,"多事之秋",100,1);
        
        data = ([
			"name":		"多事之秋",
			"target":	killer,
			"att_1":	"con",
			"att_1c":	1,
			"mark":		1,
		]);
	
		REWARD_D->imbue_att(data);	
             
        room->opengate();
	}
	::die();
}
