
// written by Cheng Bao
// modified by justdoit 05/11/2001

#include <ansi.h>
inherit NPC;

mapping *way;
object cart,F_meng;		//added F_meng by justdoit
object *protector;
mapping *read_table(string);
void del_marks_meng();		//added by justdoit
void give_reward();
void to_rob();
void be_protect();
void create_gangster(object me, object who,string name, int exp);

void create()
{
    	object ob;
    	set_name("李镖头", ({ "li biaotou","li" }) );
    	set("gender", "男性" );
    	set("age", 25);
    	set("combat_exp", 100000);
    	set("attitude", "friendly");
//    	set("vendetta_mark", "authority");
    	set("per",2);
    	set("chat_chance", 5);
    	set("chat_msg",({
    			"李镖头喝道：“闲杂人等闪开了。”\n",
            		"李镖头喝道：“快走快走，别偷懒！”\n",
        }) );
    	
    	set("NO_KILL",1);
    	set("chat_chance_combat",70);
    	set("chat_msg_combat", ({
    		"李镖头大喊道：“不好了，有人劫镖了。”\n",
            	(: be_protect :),
        }) );
	
    	set_skill("blade",50);
    	set_skill("shortsong-blade",50);
    	set_skill("force",40);
    	set_skill("parry",150);
    	set_skill("dodge",150);
    	set_skill("move",800);
    	set_skill("fall-steps",50);
    
    	map_skill("dodge","fall-steps");
    	map_skill("blade","shortsong-blade");
    	map_skill("parry","shortsong-blade");
    
    	setup();
    
    	carry_object(__DIR__"obj/jinzhuang")->wear();
    	carry_object("/obj/weapon/blade")->wield();
    	carry_object("/obj/food_item/wineskin");

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
    	object robber, robber_b;
    	string *cmds;
    	
    	remove_call_out("go");
    	for(i=0;i<sizeof(way);i++)
    	{
        	if (base_name(environment()) != way[i]["room_file"]) continue;
        	cmds=explode(way[i]["cmd_table"],";");
        	break;
    	}
    
    	robber=present("gangster",environment());
    	robber_b = present("shanxi laoda",environment());
    	if (this_object()->is_fighting() || (robber && robber->name()=="山西劫匪")
    			|| (robber_b && robber_b->name()=="山西劫匪老大"))
    	{
        	command("say 风紧，风紧");
        	call_out("go",15);
        	return;
    	}
    	
    	if (random(100)<15)
    	{
        	to_rob();
        	call_out("go",15);
        	return;
    	}
    	
    	if (i>=sizeof(way))
    	{   
        	random_move();
        	cart->move(environment());
        	message_vision("镖车隆隆驶了过来。\n",this_object());
        	call_out("go",5);
        	return;
    	}
    	
    	for(j=0;j<sizeof(cmds);j++)
        	command(cmds[j]);
    	cart->move(environment());
    	message_vision("镖车隆隆驶了过来。\n",this_object());
    	if (way[i]["delay_time"]<0)
    	{
        	call_out("give_reward",5);
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
// if one of the protectors wants to kill... then heis out of the loop
    	for(j=0;j<sizeof(enemy);j++)
        	enemy[j]->delete_temp("protecting");

    	for (i=0;i<sizeof(inv);i++)
        if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
        {
            flag=1;
            for(j=0;j<sizeof(enemy);j++)
            {
                inv[i]->kill_ob(enemy[j]);
                enemy[j]->kill_ob(inv[i]);
                enemy[j]->remove_killer(this_object());
                remove_killer(enemy[j]);
            }
        }
    	if(!flag) return;
    	message_vision("$N喊道：“你们给我上！”\n",this_object());
}

        
void get_quest(string file)
{   
    	way=read_table(file);
}

void to_rob()
{
    	int i,num;
    	object robber;
    	int exp;
    	object *inv;
    
    	exp=this_object()->query("combat_exp");
    	inv=all_inventory(environment());
// Some players joined team after getting mission.....
    	for (i=0;i<sizeof(inv);i++) {
	    	if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
	       	{
	         	if (inv[i]->query("combat_exp")>exp) 
	         		exp = inv[i]->query("combat_exp");
	        }
    	}
    	
    	message_vision("忽然间跳出一群劫匪！\n",this_object());
    	num = random(3) + 1;
    	add_temp("bandit/bandit",num+1);
    	add_temp("bandit/batch",1);
    	message_vision("李镖头高叫道：给我上，杀一个，赏银十两！\n",this_object());
    	
    	for (i=0; i<= num; i++)
    	{
        	robber=new(__DIR__"gangster");
        	robber->move(environment());
        	robber->set("combat_exp",exp);
        	create_gangster(this_object(),robber,"gangster",exp);
        	robber->kill_ob(this_object());
        	this_object()->kill_ob(robber);
        	robber->set_leader(this_object());
    	}
    	if (!random(5)){
    		add_temp("bandit/big_bandit",1);
    		robber->ccommand("say 老大、老大你终于来了！");
    		robber->ccommand("say 这下咱们能翻身了！");
    		robber->ccommand("say 小子，你还是快溜吧，咱老大可是圣教青龙堂紫薇坛红旗香主。。。");
    		robber->ccommand("say 。。。的亲舅舅！");
    		robber=new(__DIR__"gangster_1");
        	robber->move(environment());
        	robber->set("combat_exp",exp);
        	create_gangster(this_object(),robber,"gangster",exp);
        	robber->kill_ob(this_object());
        	this_object()->kill_ob(robber);
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

void set_cart(object dartcart)
	{ cart=dartcart; }

object query_cart()
	{ return cart; }

void die()
{
    	object killer;
    	object *inv,*pro_team;
    	int values;
    	int i;
	
    	values=0;
    	killer=query_temp("last_damage_from");
    	if (objectp(cart))
    	{
		
        if (arrayp(protector)) 
        {
            values*=2;
            pro_team=({0});
            if (sizeof(pro_team))
            {
                for (i=0;i<sizeof(protector);i++)
                {
                    if (objectp(protector[i])) 
                        pro_team+=({protector[i]});
                }
                if (!sizeof(pro_team))//护镖的quit光光
                {
                    destruct(cart);
			del_marks_meng();		//added by justdoit
                    ::die();
                    return;
                }
                values/=sizeof(pro_team);
                for(i=0;i<sizeof(pro_team);i++)
                {
                    if (!objectp(pro_team[i])) continue;
                    if(!intp(pro_team[i]->query("deposit")) )
                        pro_team[i]->set("deposit",0);
                    pro_team[i]->add("deposit",-values);
                    pro_team[i]->save();
                }
		
            }
        }
/*		else
		{
                if(!intp(protector->query("deposit")))
                protector->set("deposit",0);
                protector->add("deposit",-values);
                protector->save();
		}*/
		
        if (objectp(killer))
        {
            	command("chat 镖银被"+killer->name()+"抢走了！");
            	message_vision("$N打开镖车，搬走了其中的镖银！\n",killer);
            	cart->delete("no_reset"); //allow system to clean it up
            	inv=all_inventory(cart);
            	for(i=0;i<sizeof(inv);i++)
            	{
                	values+=inv[i]->value();
                	if (userp(killer))
                	{
                    		inv[i]->move(killer);
                	}
                	else
                    		destruct(inv[i]);
            	}
       }
    }
	del_marks_meng();		//added by justdoit
    	::die();
}

void give_reward()
{   
    	object *inv,*pro_team;
    	int values,i,reward;
		int reward_p, reward_e;
		int n1,n2,n3,n0,total,t;

		t = 0;
    	if (arrayp(protector)) 
    	{
        	pro_team=protector;
        	if (sizeof(pro_team))
        	{
            		for(i=0;i<sizeof(pro_team);i++)
            		{
                		if (!objectp(pro_team[i])) continue;
                		if(!intp(pro_team[i]->query("deposit")))
                    			pro_team[i]->set("deposit",0);
                	   	
                		if (!REWARD_D->check_m_success(pro_team[i],"运镖天下"))
                		{
                			REWARD_D->riddle_done(pro_team[i],"运镖天下",50,1);
                		}
                		
                		if (QUESTS_D->verify_quest(pro_team[i],"查猛护镖")) {
        					n0 = query_temp("bandit/batch");
        					n1 = query_temp("bandit/bandit");
        					n2 = query_temp("bandit/big_bandit");
        					n3 = query_temp("bandit/biaotou");
        					total = n1* 10 + n2* 20 - n3*20;
        					if (total<0)	total = 0;
        					if (total> 1000) total = 1000;	// Something is not right :D
        					message_vision(CYN"李镖头扳了扳了手指说：总共击退"+ chinese_number(n0)+"批土匪"
+chinese_number(n1) +"个，击毙土匪头子"+ chinese_number(n2)+"个，镖局人手折损"+ chinese_number(n3)+"个，
总计红包白银"+ chinese_number(total)+ "两，直接汇入"+ pro_team[i]->name(1)+"的南宫账号！\n"NOR,this_object());
							pro_team[i]->add("deposit",total*100);	
//							message_vision( pro_team[i]->query("id")+" get deposit" + total*100 + "\n", this_object());
        					pro_team[i]->save();
        				} else if (!t)
        					ccommand("say 既然你不是天机老人派来的，这红包就免了吧。\n");
						t = 1;
					}	
					
					for (i=0;i<sizeof(pro_team);i++){
						if (!objectp(pro_team[i])) continue;	
						QUESTS_D->special_reward(pro_team[i],"查猛护镖");
        			}
        	}
   	 }

// 	message_vision( "start destruct\n", this_object());
		inv=all_inventory(environment());
    	for (i=0;i<sizeof(inv);i++)
        if (inv[i]->query_temp("protecting")==cart && !userp(inv[i])){
            	message_vision("$N急急匆匆地离开了。\n", inv[i]);
        		destruct(inv[i]);
        }
//	message_vision( "start destruct self \n", this_object());
		del_marks_meng();		//added by justdoit
//      message_vision( "start destruct self 2\n", this_object()); 
        destruct(cart);
    	message_vision("$N急急匆匆地离开了。\n", this_object());
    	destruct(this_object());
    	return;
}

//added by justdoit, in order to delete marks on meng
void del_marks_meng()
{
	object room;
	room = find_object(AREA_FY"ghall");
	
	F_meng = present ("zha meng", room);
	
	if(F_meng && !userp(F_meng))
        {
                F_meng->delete("marks/gived");
        }
}
//end

void go_now()
{
    call_out("go",10);
}


void create_gangster(object me, object who,string name, int exp)
{
 	int level;
 	level=100+130*(exp-1000000)/5500000;
 	if (exp<1000000) level=100;
 	if (exp>6400000) level=230;
 	level=level*level/100;
 	if (name=="biao") {
	 	who->set("toughness",80);
	 	"/feature/nada"->reset_npc(who);
		who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")/2);
    	who->full_me();		
		who->set_skill("hammer", 70 + random(level/2));
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("changquan",50+random(level/2));
		who->set_skill("unarmed",70 + random(level/2));
	}
	if (name=="gangster" || name == "gangsterboss") {
		who->set("toughness",60);
    	"/feature/nada"->reset_npc(who);
    	who->set("agi",who->query("agi")*3/4);
    	who->set("str",who->query("str")*3/4);
//    	who->set("force_factor",who->query("force_factor")*3/4);
    	who->full_me();		
		who->set_skill("parry", 70 + random(level/2));
		who->set_skill("dodge", 70 + random(level/2));
		who->set_skill("move", 70 + random(level/2));
		who->set_skill("blade",70+random(level/2));
		who->set_skill("demon-steps",70+random(level/2));
		who->set_skill("unarmed",70+ random(level/2));
		who->set_skill("demon-strike",50+random(level/8));
		who->set_skill("demon-blade",50+random(level/8));
	}

}