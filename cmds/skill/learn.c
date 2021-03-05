// learn.c
/*	-- Modified by Silencer for FY4.1

(1)	Using Difficulty instead of learn_bonus to describe skill learning.
(2)	Removed Randomness in learning .

*/

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "说道：您太客气了，这怎麽敢当？\n",
        "像是受宠若惊一样，说道：请教？这怎麽敢当？\n",
        "笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什麽？\n",
});

int couple_learn(object me, object couple, string skill);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	string skill, teacher, master;
    	string target, cardname;
    	object ob, *list, marry_card;
    	int master_skill, my_skill, gin_cost;
    	int i,marry_flag, level;
    	int amount=0, pot;
    	
		string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });

    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
        	return notify_fail("指令格式：learn <技能> from <某人> with <潜能点>\n");

    	if( me->is_fighting() )
        	return notify_fail("临阵磨枪？来不及啦。\n");
    
    	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
        	return notify_fail("你要向谁求教？\n");
    
    	if( !living(ob) )
        	return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
    	if ( pot <=0 )
        	return notify_fail("潜能点最少是一！\n");
		
		if (userp(ob))
        	return notify_fail("现下同床异梦之事比比皆是．．．\n还是不要指望你真能学到什么了罢。\n");
        	
    	target = (string)me->query("marry");
    
    	if( !me->is_apprentice_of(ob) && !me->is_couple_of(ob)){
	        // 	Basically, if you are not his apprentice, you can't learn  
	        //   from NPC unless he returns   recognize_apprentice = 1
	        if( !(ob->recognize_apprentice(me)) && ob->query("race") == "人类") {
	            return notify_fail( ob ->name() + 
					reject_msg[random(sizeof(reject_msg))] );
			} else if(ob->query("race") != "人类"){
				return notify_fail(ob->name() + "显然听不懂你的话。\n");
			}
		}
// until here we deicde that me can learn from ob!
   	
    	if(!me->is_couple_of(ob)){ 
    		// Prevent_learn can be either from inheritance from F_MASTER
    		// Or a function in npc files. it allows you to set individual skills.
    		// But, if you override it to in a F_MASTER to play tricks 
    		// 		it will override the betrayal in F_MASTER
    		if(ob->prevent_learn(me, skill)) 
        	return notify_fail(ob->name() + "不愿意教你这项技能。\n");
    	}
    	
    	if( ob->is_couple_of(me) )    		
//		if( couple_learn(me,ob,skill))
            	return notify_fail(ob->name() + "不愿意教你这项技能。\n");
    
    	if( !master_skill = ob->query_skill(skill,1) )
        	return notify_fail("这项技能你恐怕必须找别人学了。\n");

    	my_skill = me->query_skill(skill, 1);
    	if( my_skill >= master_skill )
        	return notify_fail("这项技能你的程度已经不输于你师父了。\n");
    	
    	// 六大基本属性所对应的基本技能在学习时系数以1.5计算。
    	if ( member_array(skill, att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill)->effective_level(me)/100;
    	else
    		my_skill = my_skill * 150 /100;
    
    	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
    	if( !SKILL_D(skill)->valid_learn(me) )  return 0;

//	casue problem under query-skill-eff-lvl
    	if( (int)me->query_skill(skill,1) == 0 ) {
        	me->set_skill(skill,0);
    	}

    	if(pot >10000)	
    		return notify_fail("为防止溢出，每次学习的潜能点不能超过１００００点。\n");
    	
    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
        	return notify_fail("你没有这么多的潜能。\n");

    	if (me->query("gin")< 10)
    		return notify_fail("你的精力不够，还是先休息休息吧。\n");
    	
    	tell_object(me,"你向"+ob->name()+"请教有关「"+ SKILL_D(skill)->name() +"」的疑问。\n");
    
    	if( ob->query("env/no_teach") )
        	return notify_fail("但是" + ob->name() +"现在并不准备回答你的问题。\n");
    
    	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",me->name(), SKILL_D(skill)->name()));
    	    	
		if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
            	printf("也许是因为缺乏经验，你对%s的回答总是无法领会。\n", ob->name() );
        } else {

// WARNING ON	Seperated set of variables so it won't mess up with the old thing =============

			mapping learned_skill_points;
			int leftover, j, a_cost,a_amount, a_total;
						
			learned_skill_points=me->query_learned();
			if (mapp(learned_skill_points))
				leftover = learned_skill_points[skill];
			else
				leftover = 0;
			j = me->query_skill(skill,1);
			
			if (me->query_int()<=40)
				a_amount = (400+30*me->query_int())*2*100;
			else
				a_amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
			
	        if (me->query("national")=="苗族")	
	        	a_amount = a_amount + a_amount/20;	// 民族特性      	            	    	
	        a_amount = a_amount / SKILL_D(skill)->skill_difficulty();        	                 	
	       	if( a_amount < 1) a_amount = 1;		// 至少1：1 
	       	          
	        a_total = (j+1)*(j+1)+1 - leftover;
	        a_cost = a_total*100/a_amount+1;
			
			if (a_cost < 0)
				a_cost = 1;
				
			if (a_cost < pot) { 
				tell_object(me, HIR"风云友好提示：您所输入的潜能数（"+pot+"）大于升级所需（"+a_cost+"）点！\n"NOR);
				tell_object(me,HIR"系统自动调整所用潜能数为"+a_cost+"点。\n"NOR);
				pot = a_cost;
			}
			
// WARNING OFF =================================================================================

            	printf("你听了%s的指导，似乎有些心得。\n", ob->name());
            	
            	me->add("learned_points", pot); 
				me->add("annie/skill_cost/"+skill,pot);
    	         
    	        if (me->query_int()<=40)
    	        	amount = (400+30* me->query_int()) *2 * pot;
    	        else
    	        	amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*pot) ;
                       		
            	if (me->query("national")=="苗族")	
            		amount = amount + amount/20;	// 民族特性
            	            	    	
            	amount = amount / SKILL_D(skill)->skill_difficulty();
            	            	           	                 	
            	if( amount < 1) amount = 1;		// 至少1：1            	

// DEBUG on
		if (wizardp(me) && me->query("env/debug")) {
			write("skill difficulty is "+ SKILL_D(skill)->skill_difficulty() + "\n");
			write("learning efficiency is: 1 point 潜能 == " + amount/pot + "\n");
		}
// DEBUG off

            	me->improve_skill(skill,amount);
        }
	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	learn <技能> from <某人> with <潜能点>[0m
[0;1;37m────────────────────────────────[0m   

风云中共有四种获取技能的途径：	读书（study）
				[1;31m学习（learn）[0m
				钻研（research）
				练习（practice）

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请
教的对象在这项技能上的造诣必须比你高，而你经由这种方式学习得来
的技能也不可能高於你所请教的人，然而因为这种学习方式相当於一种
经验的传承，因此学习可以说是熟悉一种新技能最快的方法。

通常，一个人刚学到一种新技能是不会有什麽疑难问题的，而是经由实
际上的应用中遭遇问题，这些问题对於学习一种新技能的过程是很重要
的，尤其是各种作为其他技能基础的基本技能，更需要经由「发现问题
—解决问题」的过程才能得到较好的效果因此我们将这种发现问题的过
程用「潜能」的观念表示，一个人能够自己发现某些问题，表示他(她)
有解决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令来
向其他人请教，而获得进步。

FY2005中学习不再消耗精力。

至於如何知道你能从对方学到什麽技能，如果对方是你的师父，可以用
 skills 指令直接查看。

每N点潜能对应的技能增加对应的具体公式为：
（1）才智《=40时，
	= N *（400 + 30*才智）*2 /学习难度 
（2）才智〉40时， 
	= N*((（int*10）^0.03)*871-950)*173/5/学习难度

所学的数值在计算的最后一步取整。
大部分技能的学习难度在１００至２５０，

学习的效率与以下因素相关：
（1）技能种类：不同的武功学习难度不同，可用skills命令察看。
（2）民族特性，苗族的学习效率比较高（上面公式再+5%）

学习技能的限制：
（1）没有师傅喜欢三心二意、朝楚暮秦的弟子，你每叛师一次，下一个
师傅愿意教你的技能等级就会减少二十级。同时，师门专有的武功进界
（ａｂｉｌｉｔｙ）在判师后也就没用了。

升级的条件
当你的学习点数大于下一级的平方加一时升级，
也就是说，如果你的技能等级为n，在学习点数（注意，不是潜能点数）
大于(n+1)*(n+1)+1时升级。

举例
＊蝶恋花剑法 (diesword)                  - 粗通皮毛  22/  530
此地 530 = 23*23 + 1， 当你再花费一点潜能学习时升级成为
＊蝶恋花剑法 (diesword)                  - 粗通皮毛  23/  0

** 六大基本属性对应的相关技能（读书识字、诵经、扑击格斗、基本
轻功、占卜学、基本内功）在学习的时候系数计算为150。

其他相关指令 : practice、study、research

[0;1;37m────────────────────────────────[0m   
HELP
        );
    return 1;
}


int couple_learn(object me, object couple, string skill)
{
	int i, div,div1,mylvl, herlvl, ratio=0;
	if(!userp(couple)) return 0;
	mylvl = me->query_skill(skill,1);
	herlvl = couple->query_skill(skill,1);
	div = (int) me->query("divorced");
	div1 = (int) couple->query("divorced");
	for(i=1; i<=div1; i++) 
		ratio+=25;
	if(div1&&(mylvl>=herlvl-ratio)){
		message_vision("$N想起$n从前离婚的事，忽然觉得心里很不舒服，一时丧失了学习的兴趣。\n",me,couple);
		return 1;
	}
	if(div&& (mylvl >= herlvl / 2) ){
		message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前离婚的事情...。\n", couple, me );	
		return 1;	
	}
	return 0;
}
