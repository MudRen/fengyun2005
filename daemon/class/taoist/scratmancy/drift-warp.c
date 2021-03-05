#include <ansi.h>
#include <command.h>
#include <login.h>
inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
         string err;
         int extra;
         
        if(me->query("class")!="taoist")
         	return notify_fail("只有三清宫弟子才可以画符。\n");

        if((int)me->query_skill("scratmancy",1) < 50)
                return notify_fail("画九遁符至少需要50级三清符术。\n");

        if( sheet->name() != "桃符纸" )
                return notify_fail("遁天符要画在桃符纸上！\n");
	
        if( (int)me->query("mana") < 100 ) 
		return notify_fail("画九遁符至少需要100点法力。\n");
	write("你要在符上写什么？");
	input_to( (: call_other, __FILE__, "select_target", me,sheet :));

	return 1;
}

void select_target(object me, object sheet,string name)
{
	object ob,newsheet;
	string fplace;
	int level;
	
	if( !name || name=="" ) {
		write("中止写符。\n");
		return;
	}

	switch(name)	{
		case "fengyun":
		case "风云城":
			level = 50;
			fplace="风云城";
			break;
		case "dazhaosi":
		case "大昭寺":
			level = 60;
			fplace="大昭寺";
			break;
		case "songguan":
		case "松谷庵":
			level = 80;
			fplace="松谷庵";
			break;
		case "daimiao":
		case "岱庙":
			level = 80;
			fplace="岱庙";
			break;
		case "bianfudao":
		case "蝙蝠岛":
			level = 100;
			fplace="蝙蝠岛";
			break;
		case "biancheng":
		case "边城":
			level = 130;
			fplace="边城";
			break;
		case "baiyundao":
		case "白云岛":
			level = 150;
			fplace="白云岛";
			break;
		default:
			level = 50;
			fplace="三清道观";
			break;
	}
	
	if (me->query_skill("scratmancy",1) < level) {
		write ("你的三清符术太低，无法感应到这个鼎神。（需"+level+"级）\n");
		return;
	}
	
	if (me->query("mana")< 100) {
		write ("至少需要100点法力。\n");
		me->add("mana", -50);
		me->force_status_msg("mana");
	}
	
	sheet->add_amount(-1);
	seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "遁天符" NOR, ({ "drift-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->set("burn_person",me);
        newsheet->move(me);
        me->save();
       	
	newsheet->set("long","一张道家的遁天符，上面用篆文写着"+fplace+"几个字。\n");
	newsheet->set("flying_place",fplace);
	newsheet->set("level", level);
			
        message_vision("$N写了一道去"+fplace+"的遁天符。\n" NOR, me);
        	
        return ;
}

int do_warp(object sheet)
{
        object env, me;
        string fplace;
        me=this_player();
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty"))
    		return notify_fail("此地不能使用遁天符。\n");  
		if (me->is_fighting())
    		return notify_fail("哎呀，这个时候烧符是没有用的，还是撒脚丫子逃吧。\n");  
	
		if (stringp(this_player()->query_temp("no_move")))
        	return notify_fail(this_player()->query_temp("no_move"));
        	
		me->start_busy(2+random(2));
		fplace=(string)sheet->query("flying_place");
        env = environment(me);
        message("vision",me->name()+WHT"脚踏天罡步，凝神祭起一张遁天符。 \n"NOR, env,me);
        tell_object(me, WHT"你脚踏天罡步，凝神祭起一张遁天符。 \n"NOR);
        message("vision",YEL "平地涌起一阵迷茫的烟雾，"+me->name()+YEL"的身影隐没在烟雾中... \n"NOR,env,me);
	
	if(sheet->query("burn_person")==this_player())
		call_out("move_him",1+random(4),this_player(),fplace);
	else
		message_vision("结果什么都没有发生。\n",this_player());
	return 1;
}



int move_him(object me,string fplace)
{
	string place;		
  	message("vision", "WHT 烟雾慢慢散去，$N已经消失得无影无踪。  \n"NOR
  		,me,({me}));
        message("vision",
                MAG "周围的景色如飞般向后掠去，你不禁有点头晕目眩。 \n"
YEL "你感到周围的景色终于凝顿下来，你已经来到了另一个地方。 \n\n"NOR, me);
 	switch(fplace) {
 		case "三清道观":	// ding_sq
 			place="/d/taoguan/da_dian";
 			break;
 		case "大昭寺":		// ding_gw
 			place="/d/guanwai/templeyard";
 			break;
 		case "松谷庵":		// ding_hs
 			place="/d/huangshan/songgu";
 			break;
 		case "岱庙":		// ding_dm
 			place="/d/daimiao/tongting";
 			break;
 		case "风云城":	// ding_fy
 			place="/d/fy/hiretem";
 			break;
 		case "蝙蝠岛":		// ding_bat
 			place="/d/bat/room2";
 			break;
 		case "边城":		// ding_bc
 			place="/d/biancheng/temple";
 			break;	
 		 case "白云岛":		// ding_by
 			place="/d/baiyun/jietiandian";
 			break;	
	}
	if(!stringp(place))
		place="/d/taoguan/da_dian";
	TASK_D->flying_risk(me);
	me->move(place);
	message("vision",YEL "你周围忽然起了一阵怪风，"+me->name()+"的身影似乎从风中凝结般出现在眼前。 \n"NOR,
		place, ({me}) );
      
        return 1;
        
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
