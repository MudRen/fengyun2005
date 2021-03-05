#include <ansi.h>
inherit SMART_NPC;

mapping *way;
object *protector;

mapping *read_table(string);

int  init_escort(object me, int exp);

void go_now();
void get_quest(string file);
void set_protector(object *prot);
void del_marks_giver();
void give_reward();
void to_rob();
void be_protect();



void create()
{
    	object ob;
    	set_name("胖姑娘", ({ "fat lady","fatty" }) );
    	set("gender", "女性" );
    	set("age", 19);
    	
    	set("NO_KILL",1);
    	set("route","/d/biancheng/escort_1");
    	set("escortee","passive");
    	set("pfm_chance", 20);
    	set("robber1",__DIR__"ass1");
    	set("rob_num",1);
    	 	
    	set("combat_exp", 100000);
    	set("attitude", "friendly");
    	
    	set("chat_chance", 5);
    	set("chat_msg",({
    			query("name")+ "说：慢点、慢点、你想把我累死阿！\n",
//    			"胖姑娘说：还有多远，快到了么？\n",
        }) );
    	
    	set("chat_chance_combat",100);
    	set("chat_msg_combat", ({
    			(: be_protect :),
        }) );
	
    	setup();
       	carry_object("/obj/armor/cloth")->wear();
}


int		init_escort(object me, int exp) {
		
		object *team, escortee;
		int i;
						
		// 设置路线
		get_quest(query("route"));
		
		// 设置escorter/escortee关系
		team = me->query_team();
		if (!team || !sizeof(team))	{
			team=({me});
			set_protector(team);
			me->set_temp("protecting",this_object());
		}	else	{
			set_protector(team);
			for(i=0;i<sizeof(team);i++)
       			team[i]->set_temp("protecting",this_object());
    	}
		me->set_leader(this_object());
				
    	go_now();
		return 1;
}	

int random_move()
{
		mapping exits;
		string *dirs, direction;
		object env;
		
		if( !mapp(exits = environment()->query("exits")) ) return 0;
		
		dirs = keys (exits);
		direction = dirs[random(sizeof(dirs))];
		command("go " + direction);
		return 1;
}

//overwrite base npc random_move() function
void go()
{
    	int i,j;
    	object robber;
    	string *cmds;
    	
    	remove_call_out("go");
    	for(i=0;i<sizeof(way);i++)
    	{
        	if (base_name(environment()) != way[i]["room_file"]) continue;
        	cmds=explode(way[i]["cmd_table"],";");
        	break;
    	}
    
    	robber=present("veiled man",environment());
    	if (this_object()->is_fighting() || (robber && robber->name()=="蒙面人"))
    	{
        	call_out("go",15);
        	return;
    	}
    	
    	if (!SMART_D->check_health(this_object(),50)){
    		command("say 不行，痛死我了，让我喘口气。");
    		add_temp("bandit/hurt",1);
    		message_vision("$N深深吸了几口气，开始运功疗伤。\n",this_object());
    		call_out("go",15);
    		return;
    	}
    	
    	if (random(100)<15)
    	{
        	to_rob();
        	call_out("go",15);
        	return;
    	}
    	
    	// 迷宫中未定房间或小错误的预防。
    	if (i>=sizeof(way))
    	{   
        	random_move();
        	message_vision("$N四处看了看，似乎拿不定主意。\n",this_object());
        	call_out("go",5);
        	return;
    	}
    	
    	for(j=0;j<sizeof(cmds);j++) {
//        	command("say "+ cmds[j] +"");
        	command(cmds[j]);
    	}
    	
    	if (way[i]["delay_time"]<0)
    	{
        	give_reward();
        	return;
    	}
    	call_out("go",way[i]["delay_time"]);
    	return;
}	


void be_protect()	{
    	
    	int i,j,flag;
    	object *inv,*enemy;
	
    	inv=all_inventory(environment());
    	enemy=query_enemy();
    	
    	if (!enemy || sizeof(enemy)<1)	return;
    	
// if one of the protectors wants to kill... then heis out of the loop
    	for(j=0;j<sizeof(enemy);j++)
        	enemy[j]->delete_temp("protecting");

    	for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")==this_object())
        {
            flag=1;
            for(j=0;j<sizeof(enemy);j++)
            {
                if (!inv[i]->is_fighting(enemy[j])) {
                	inv[i]->kill_ob(enemy[j]);
                	enemy[j]->kill_ob(inv[i]);
                }
                if (query("escortee")== "passive") {
                	enemy[j]->remove_killer(this_object());
                	remove_killer(enemy[j]);
                }
            }
        }
    	  	
    	
    	if (query("escortee")!="passive" && is_fighting())
    		auto_smart_fight(query("pfm_chance"));
    	else
    		message_vision("胖小姑娘大叫：救命啊，救命啊，有人劫、劫、劫色了！\n",this_object());
    	   	
    	return;
}

        
void get_quest(string file)
{   
    	way=read_table(file);
//    	CHANNEL_D->do_sys_channel("sys",sprintf("%O",way));
}

void to_rob()
{
    	int i, num;
    	object robber;
    	int exp;
    	object *inv;
    
    	exp=this_object()->query("combat_exp");
    	inv=all_inventory(environment());

// Some players joined team after getting mission.....
    	for (i=0;i<sizeof(inv);i++) {
	    	if ( inv[i]->query_temp("protecting")==this_object())
	       	{
	         	if (inv[i]->query("combat_exp")>exp) 
	         		exp = inv[i]->query("combat_exp");
	        }
    	}
    	
    	num = query("rob_num");
    	
    	add_temp("bandit/bandit",num);
    	    	    	
    	message_vision("忽然间跳出"+chinese_number(num)+"个蒙面人！\n",this_object());
    	message_vision(CYN"蒙面人叫道：怨有头债有主，没事儿的闪开，胖猪拿命来！\n"NOR, this_object());
    	  	
    	for (i=0;i<num;i++)
    	{
        	robber=new(query("robber1"));
        	robber->move(environment());
        	robber->set("combat_exp",exp);
        	"/feature/nada"->reset_npc(robber);
    		
	   		robber->full_me();
    		SMART_D->auto_npc_setup(robber, "蒙面人", 200, 180, 1, "/obj/weapon/", "random", "random", 1); 	
        	robber->kill_ob(this_object());
        	kill_ob(robber);
        	robber->set_leader(this_object());
    	}
    	  	
    	be_protect();
}
	
mapping *read_table(string file)
{
    	string *line, *field, *format;
    	mapping *data;
    	int i, rn, fn;

    	line = explode(read_file(file), "\n");
    	data = ({});
    	for(i=0; i<sizeof(line); i++) {
        	if( line[i]=="" || line[i][0]=='#' ) continue;
        	if( !pointerp(field) ) {
            		field = explode( line[i], ":" );
            		continue;
        	}
        	if( !pointerp(format) ) {
            		format = explode( line[i], ":" );
            		continue;
        	}
        	break;
    	}

    	for( rn = 0, fn = 0; i<sizeof(line); i++) {
	        if( line[i]=="" || line[i][0]=='#' ) continue;
	        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
	        sscanf( line[i], format[fn], data[rn][field[fn]] );
	        fn = (++fn) % sizeof(field);
	        if( !fn ) ++rn;
    	}
    	return data;
}

void set_protector(object *prot)
	{ protector=prot; }

object *query_protector()
	{ return protector; }


void die()
{
    	del_marks_giver();		//added by justdoit
    	::die();
}

void give_reward()
{   
    	object *inv,*pro_team;
    	int values,i,reward;
		int reward_p, reward_e,num,num2,total;
	
    	    	if (arrayp(protector)) 
    	{
           	pro_team=protector;
        	if (sizeof(pro_team))  	{    	        		            		
        		for(i=0;i<sizeof(pro_team);i++)
        		{
            		if (!objectp(pro_team[i])) continue;
            			              	   	
              		if (!REWARD_D->check_m_success(pro_team[i],"胖胖上香"))
            		{
            			REWARD_D->riddle_done(pro_team[i],"胖胖上香",50,1);
            		}
            		
            		if (QUESTS_D->verify_quest(pro_team[i],"胖胖上香")){
            			num = query_temp("bandit/bandit");
				    	num2 = query_temp("bandit/hurt");
				    	total = num*50-20*num2-5;
				    	if (total<0) total=0;
    					if (num > 40) num=40;
    					if (total>2000) total=2000;
    					tell_object(pro_team[i],CYN"
胖胖猛地又跳了回来说：走了二十三里平路五十七里山路，小毛贼一共打死"+ chinese_number(num)+"个，搜得白银"+(50*num)+"
两，本姑娘身受重伤"+chinese_number(num2)+"次云南白药用去"+(20*num2)+"两，买牛肉干扣去五两，剩余红包白银"+ chinese_number(total)+ "
两，直接汇入"+ pro_team[i]->name(1)+"的南宫账号！\n"NOR,this_object());
        				pro_team[i]->add("deposit",total*100);
        				if (pro_team[i]->query("quest/quest")=="胖胖上香") {
        					pro_team[i]->add("quest/difficulty",(num-2)*20);
//        					tell_object(pro_team[i],"difficulty is" + pro_team[i]->query("quest/difficulty")+"\n");
        				}
        					
        			}	
        		}
	        	for (i=0;i<sizeof(pro_team);i++){
	        		if (!objectp(pro_team[i])) continue;	
					QUESTS_D->special_reward(pro_team[i],"胖胖上香");
        		}
        	}
   	 	}
		inv=all_inventory(environment());
    	for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")== this_object() && !userp(inv[i]))
           	destruct(inv[i]);
		del_marks_giver();		
    	    		
    	;

    	destruct(this_object());
    	return;
}

void del_marks_giver()
{
		object room, giver;
		room = find_object(AREA_BIANCHENG"teashop");
	
		giver = present ("fatman", room);
	
		if(giver && !userp(giver))
        	giver->delete("marks/gived");
}


void go_now()
{
    call_out("go",10);
}