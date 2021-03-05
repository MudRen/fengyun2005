// learn.c

#include <skill.h>

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
    	object ob, *list, marry_card;
    	int master_skill, my_skill, gin_cost;
    	string target, cardname;
    	int i,marry_flag;
    	int amount=0, pot;
    

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
    	target = (string)me->query("marry");
    
    	if( !me->is_apprentice_of(ob) && !me->is_couple_of(ob)){
// add by xxder to check the race of learning target.
        if( !(ob->recognize_apprentice(me)) && ob->query("race") == "人类") {
            return notify_fail( ob ->name() + 
				reject_msg[random(sizeof(reject_msg))] );
		} else if(ob->query("race") != "人类"){
			return notify_fail(ob->name() + "显然听不懂你的话。\n");
		}
	}
// until here we deicde that me can learn from ob!

    	if( !master_skill = ob->query_skill(skill,1) )
        	return notify_fail("这项技能你恐怕必须找别人学了。\n");
    
    	if(!me->is_couple_of(ob)){ 
    		if(ob->prevent_learn(me, skill)) 
        	return notify_fail(ob->name() + "不愿意教你这项技能。\n");
    	}
    	
    	if( ob->is_couple_of(me) )
	if( couple_learn(me,ob,skill))
            	return notify_fail(ob->name() + "不愿意教你这项技能。\n");
    
    	my_skill = me->query_skill(skill, 1);
    	if( my_skill >= master_skill )
        	return notify_fail("这项技能你的程度已经不输于你师父了。\n");
    	my_skill = my_skill*SKILL_D(skill)->effective_level()/100;
    
    	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
    	if( !SKILL_D(skill)->valid_learn(me) )  return 0;
//    gin_cost = 100 / (int)ob->query_int();
     	gin_cost = 100 / ( 10 + (int)me->query_int());
//<- Modified by neon
//	casue problem under query-skill-eff-lvl
    	if( (int)me->query_skill(skill,1) == 0 ) {
        	gin_cost *= 2;
        	me->set_skill(skill,0);
    	}
    
    	gin_cost *= pot;
    	gin_cost = gin_cost/2;
    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
        	return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
    	tell_object(me,"你向"+ob->name()+"请教有关「"+ SKILL_D(skill)->name() +"」的疑问。\n");
    
    	if( ob->query("env/no_teach") )
        	return notify_fail("但是" + ob->name() +"现在并不准备回答你的问题。\n");
    
    	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",me->name(), SKILL_D(skill)->name()));

    	if( (int)ob->query("sen") > gin_cost/5 + 1 ) {
        	if( userp(ob) ) ob->receive_damage("sen", gin_cost/5 + 1);
    	} else {
        	write("但是" + ob->name() +  "显然太累了，没有办法教你什麽。\n");
        	tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
        	return 1;
    	}
    	
    	if( (int)me->query("gin") > gin_cost ) {
	        if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
	            	printf("也许是因为缺乏经验，你对%s的回答总是无法领会。\n", ob->name() );
	        } else {
	            	printf("你听了%s的指导，似乎有些心得。\n", ob->name());
	            	me->add("learned_points", pot);
	            
	            	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
	            	if((amount < -50) && (my_skill < 75)) amount = -50;
	// however, we won't make learn so easy
	//      amount  += random((int)me->query_int()+((float)me->query("combat_exp")/1000)
	//              + SKILL_D(skill)->learn_bonus() ;
	            	amount += SKILL_D(skill)->learn_bonus() +
	                	(int)me->query_int() * (int)me->query_int() +
	                	to_int(pow(to_float((int)me->query("combat_exp")),0.3));
	//        write(sprintf("%d\n",amount));
	            	amount = amount/50 + random(amount/50);
	          write(sprintf("%d\n",amount));
	            	if (me->query("national")!="苗族")
	            		amount = amount *97/100;
	            	if( amount < 2) amount = 2;	
	          write(sprintf("%d\n",amount));
	            	amount *= pot;
	            	me->improve_skill(skill,amount);
	        }
	} else {
	        gin_cost = me->query("gin");
	        write("你今天太累了，结果什麽也没有学到。\n");
    	}
    
    me->receive_damage("gin", gin_cost );
    
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : learn <技能> from <某人> with <潜能点>

这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

通常，一个人刚学到一种新技能是不会有什麽疑难问题的，而是经由实际上的应用中
遭遇问题，这些问题对於学习一种新技能的过程是很重要的，尤其是各种作为其他技
能基础的基本技能，更需要经由「发现问题—解决问题」的过程才能得到较好的效果
因此我们将这种发现问题的过程用「潜能」的观念表示，一个人能够自己发现某些问
题，表示他(她)有解决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令
来向其他人请教，而获得进步。
(PS. 潜能还有其他更广义的定义，这里只是其中之一 )

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

至於如何知道你能从对方学到什麽技能，如果对方是你的师父，可以用 skills 指令
直接查看，如果不是你的师父，那麽通常会有其他的提示，你只好自己想办法。

其他相关指令 : practice、study
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
