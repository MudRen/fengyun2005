#include <ansi.h>

inherit NPC;
//void backattack();
void create()
{

	set_name("侍卫", ({ "shiwei" }) );
	set("long", "这是一位朝廷的带刀侍卫，听从朝廷命官的指挥。\n");
	set("attitude", "friendly");
	set("title","朝廷 七品带刀侍卫");
	set("class","baiyun");
	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 100000);
	
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 70);
	set_skill("feixian-steps",70);
	set_skill("feixian-sword",70);
	set_skill("changquan",70);
	set_skill("unarmed",70);
	map_skill("unarmed","changquan");
	map_skill("sword","feixian-sword");
	map_skill("parry","feixian-sword");
	map_skill("dodge","feixian-steps");
	map_skill("move","feixian-steps");

	setup();

	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void leave()
{
	object owner,*pros;
	if (environment())
		message("vision",name() + "闪了闪就消失不见了。\n" , environment(),	this_object() );
    if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}


void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_kill","kill");
	add_action("do_dismiss","dismiss");	
}

void heart_beat()
{
	object leader;
	
	::heart_beat();

    if(!this_object()) 		return;
    if (!environment())		return;
        		
	if(query_temp("is_unconcious")||is_busy())
		return ;
		
	if(query("possessed"))
	{
		leader=query("possessed");
		if(environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N匆匆离去。\n",this_object());
			move(environment(leader));
			message_vision("$N走了过来。\n",this_object());
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

int do_dismiss(string arg)
{
	object who,obj;
	
	if(!arg) return 0;
	if(!obj=present(arg,environment()))
		return 0;
	if(obj!=this_object()) return 0;
	who=this_player();
	if(who!=query("possessed")) return 0;
	if (obj->is_fighting())
    {
    	tell_object(who,"该士兵正在战斗中，无法解散。\n");	
    	return 1;
    }	
	
    if (query("is_leaving")) {
    	tell_object(who,"该护卫已经被解散了。\n");
    	return 1;
    }
    
	if(who->query("sen")<200)
	{
		tell_object(who,"你的心神不够，无法对兵士下命令。\n");
		return 1;
	}
	who->receive_damage("sen",200);
	
	message_vision("$N对$n说道：“这里不需要你了，下去吧。。。”\n",who,obj);
	obj->ccommand("inn "+who->query("id"));
	set("is_leaving",1);
	remove_call_out("leave");
	call_out("leave",1);
	return 1;
}


int do_kill(string arg)
{
	object victim,who;
	
	who=this_player();
	if(!arg) return 0;
	if(environment()->query("no_fight"))
		return 0;
	victim=present(arg,environment());
	if(!victim) return 0;
	if( !victim->is_character() || victim->is_corpse() )
		return 0;
	
	if (query("possessed"))
	if (!COMBAT_D->legitimate_kill(query("possessed"), victim))	return 0;
	
	if(victim==who) return 0;
	if(victim->query("possessed")==who && victim->query("id")=="shiwei")
	{
		tell_object(who,"你不能杀自己的护卫，否则部下会离心离德的。\n");
		return 1;
	}
	if(victim==query("possessed") && victim->query("possessed")==query("possessed"))
	if(who->query("vendetta_mark")!="authority")
	{
		message_vision("$N喝道：“大胆匪徒，竟然敢加害朝廷命官！！”\n",this_object());
		kill_ob(who);
	}
	if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
	{
		message_vision("$N对"+victim->query("name")+"喝道：“大胆匪徒，还不速速束手就擒？”\n",this_object());
		kill_ob(victim);
	}
	return 0;
}

string *lname = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳","邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候","司马",
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴","梁丘","左丘","东门","西门",
    });


void invocation(object who, int level)
{
	int i,hp,str,base;
	object *enemy,*pros;
	
	set_name(lname[random(sizeof(lname))]+"侍卫",({ "shiwei"}) );
	set("combat_exp",100000 + who->query("combat_exp")*3/4);
	set("level", F_LEVEL->get_level(query("combat_exp")));	// around 110 cap
	
	"/feature/nada"->reset_npc(this_object());

	hp = 500 + who->query("max_kee")/2
		+ who->query("max_kee")* F_ABILITY->check_ability(who,"huwei_add")/100;
	set("max_kee",hp);
	
	if (hp> 2000) hp = 2000;	// weakness
	set("max_sen",hp/2);
	set("max_gin",hp/2);
	
	str = query_str();
	delete("force_factor");
	set("str",str/2);
	
	// level = 400 maxium for shiwei			
	base = level /4;	
	set_skill("sword", 30 + base);
	set_skill("parry", 30 + base);
	set_skill("dodge", 30 + base);
	set_skill("move",  30 + base);
	set_skill("unarmed", 30 + base);
	set_skill("feixian-steps",5+who->query_skill("puti-steps",1)/2);
	set_skill("feixian-sword",5+who->query_skill("yue-spear",1));
	set_skill("changquan",5 + who->query_skill("changquan",1));
	
	full_me();
	
	set("possessed",who);
	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
}


void die()
{
	object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	message_vision("\n$N惨叫一声，倒在地上断气了。\n\n", this_object());
	destruct(this_object());
}



int attack()
{
	object opponent,owner;
	int exp,extra;	        

     opponent = select_opponent();
     if(objectp(opponent)) {
     	set_temp("last_opponent", opponent);
		owner=query("possessed");
		if(opponent==owner)
		{
			this_object()->ccommand("ah");
			message_vision("$N对$n说道：“不知是大人，小人刚才多多冒犯了，还请大人恕罪。”\n",this_object(),owner);
			this_object()->ccommand("escape");
			leave();
			return 1;
		}
	
		exp=opponent->query("combat_exp");               		
		if (objectp(owner))
			extra = owner->query_skill("leadership",1);
		else
			extra = 1000;		// Some NPC ?
		
		if(random(extra)) 
			COMBAT_D->fight(this_object(), opponent);
		else	if(random(exp)>this_object()->query("combat_exp"))
        	{
 				message_vision("$N大声喊道：“贼人势大，还是保命为先吧。”\n",this_object());
 				this_object()->ccommand("escape");
 				leave();
             }
       return 1;
     } else
     	return 0;
}
