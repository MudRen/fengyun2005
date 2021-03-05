// judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;
string *output = ({
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B"+
" B",
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"+
"B"
});


string *c_num= ({
"      ;'       B"+
" , ''';;'''' , B"+
",;';;';;';;';;'B"+
";' ,, ;; ,, ;' B"+
"    ,;',';,,   B"+
",,'',,,;;,,;';'B"+
"         ;'    B"+
"     ',,;'     B"+
"       ';'     B"+
"               B",
"               B"+
"               B"+
"               B"+
"               B"+
"               B"+
",,,,,,,,,,,;,  B"+
"               B"+
"               B"+
"               B"+
"               B",
"               B"+
"               B"+
"               B"+
"  ,,,,,,,,,;,  B"+
"               B"+
"             , B"+
"'''''''''''''''B"+
"               B"+
"               B"+
"               B",
"           ,   B"+
"  '''''''''''  B"+
"               B"+
"  ,,,,,,,,,;,  B"+
"               B"+
"             , B"+
"'''''''''''''''B"+
"               B"+
"               B"+
"               B",
",            , B"+
";;'';;'';;'';;'B"+
";;  ;;  ;;  ;; B"+
";;  ;;  ;;  ;; B"+
";; ;;   ;;,,;; B"+
";;,'     ''';; B"+
";;'''''''''';; B"+
"'           '  B"+
"               B"+
"               B",
" ,,,,,,,,,,,;, B"+
"     ;;        B"+
"     ;;   ,    B"+
" '''';;'';;'   B"+
"     ;;  ;;    B"+
"    ;;   ;;    B"+
"    ;;   ;;  , B"+
"'''''''''''''''B"+
"               B"+
"               B",
"     ',,       B"+
"      ';;      B"+
",,,,,,,;,,,,,;,B"+
"     ,  ,      B"+
"    ;;'  ;,    B"+
"   ,;'    ;,   B"+
"  ,;'      ;;  B"+
" ,'         ;' B"+
"               B"+
"               B",
"      ,        B"+
"      ;;       B"+
"      ;;     , B"+
"    ,,;;,,'''''B"+
"''''  ;;       B"+
"      ;;     , B"+
"      ;;,,,,,;,B"+
"       ''''''' B"+
"               B"+
"               B",
"    ,   ;,     B"+
"    ;;  ;;     B"+
"    ;;  ;;     B"+
"    ;;  ;;     B"+
"   ,;'   ;;    B"+
"  ,;'    ';,   B"+
" ,;'      ';;, B"+
",'          ';'B"+
"               B"+
"               B",
"     ;,        B"+
"     ;;   ,    B"+
" '''';;'';;'   B"+
"     ;;  ;;    B"+
"    ,;'  ;;    B"+
"   ,;'   ;;    B"+
"  ,;'    ;;  ; B"+
",''      ';;;;'B"+
"               B"+
"               B",
"      ;,       B"+
"      ;;       B"+
"      ;;       B"+
"'''''';;'''''' B"+
"      ;;       B"+
"      ;;       B"+
"      ;;       B"+
"      ;'       B"+
"               B"+
"               B"
});
string *c_digit = ({
"      ;'       B"+
" , ''';;'''' , B"+
",;';;';;';;';;'B"+
";' ,, ;; ,, ;' B"+
"    ,;',';,,   B"+
",,'',,,;;,,;';'B"+
"         ;'    B"+
"     ',,;'     B"+
"       ';'     B"+
"               B",
"      ;,       B"+
"      ;;       B"+
"      ;;       B"+
"'''''';;'''''' B"+
"      ;;       B"+
"      ;;       B"+
"      ;;       B"+
"      ;'       B"+
"               B"+
"               B",
",,,,,,,,,,,,,;,B"+
"     ,;'       B"+
"   ;,;,,,,,;,  B"+
"   ;;     ;;   B"+
"   ;;,,,,,;;   B"+
"   ;;     ;;   B"+
"   ;;     ;;   B"+
"   ;'''''';'   B"+
"               B"+
"               B",
"          ,;,  B"+
" ,,,,;;'''''   B"+
"      ;;       B"+
",,,,,,;;,,,,,;,B"+
"      ;;       B"+
"      ;;       B"+
"      ;;       B"+
"      ;'       B"+
"               B"+
"               B"
});
int in_ask, answer;
string my_number(int num);
string addcolor(string input);
void create()
{
	set_name("审判官", ({ "judge" }) );
	set("short", "专门对付机器人的" HIY "审判官"NOR "(judge)" );
	set("long",
		"这是一位审查玩家是否是机器人的审判官，你必须答对(answer)他三个问题才能\n"
		"脱离他的掌握。\n");

	set("gender", "男性");
	set("age", 40);

	set("str", 100);
	set("int", 100);
	set("cor", 100);

	set("combat_exp", 9000000);
	set("score", 0);

	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);

	setup();

	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	"/cmds/std/look"->look_room(this_player(),environment(this_object()));
	if(!wizardp(this_player()))
	add_action("do_nothing", "");
	add_action("do_answer", "answer");

}

int do_nothing()
{
return 1;
}

void chat()
{
	int a, b, c;
	string oper;
	
	if( in_ask || random(20) > 10 ) return;
	delete_temp("wrong");
	a = random(100000000);
	b = random(100) + 1;
	switch(random(1)) {
		case 0: 
			answer = a;
//			oper = chinese_number(a) + "加上" + chinese_number(b)+ "等於多少？";
			oper = my_number(answer);
			break;
		case 1: 
			answer = a - b;
			oper = chinese_number(a) + "减去" + chinese_number(b)+ "等於多少？";
			break;
		case 2: 
			if( a * b < 200 ) {
				answer = a * b;
				oper = chinese_number(a) + "乘上" + chinese_number(b)+ "等於多少？";
			} else {
				answer = (a * b) % 10;
				oper = chinese_number(a) + "乘上" + chinese_number(b)+ "，个位数等於多少？";
			}
			break;
		case 3: 
			answer = a % b;
			oper = chinese_number(a) + "除以" + chinese_number(b)+ "馀於多少？";
			break;
		case 4:
			oper = chinese_number(a) + "和" + chinese_number(b)+ "的最大公因数是多少？";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
	}
	message_vision(oper,this_object());
	command("say 以上中文数字是多少？请在二十秒内作答(answer)。");
	in_ask = 1;
	call_out("say_answer", 40);
}

void say_answer()
{
	command("say 这麽简单都不会？答案等於：" + sprintf("%d",answer) + "。");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("你必须等下一题。\n");
	if( !arg ) return notify_fail("请你回答一个数字。\n");

	message_vision( CYN "$N答道：" + arg + "\n"NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say 答对了！");
			command("pat " + this_player()->query("id") );
			in_ask = 1;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say 很好，你看起来不像机器人，你可以走了。\n");
				if( stringp(s = this_player()->query_temp("old_startroom")) )
					this_player()->set("startroom", s);
				this_player()->delete_temp("robot_check");
				if( stringp(s = this_player()->query_temp("last_location")) )
					this_player()->move(s);
				else
					this_player()->move(START_ROOM);
			}
		} else {
			command("say 错！");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 ) {
				command("say " + this_player()->name() + "你再给我乱猜啊，去死吧。\n");
				this_player()->receive_damage("kee", 100, this_object());
				this_player()->die();
			}
		}
	}
	return 1;
}

string my_number(int num)
{
 string outstring;
 int out;
 int orinum;
 string *out8,*out7,*out6,*out5,*out4,*out3,*out2,*out1;
	orinum = num;
	switch(random(10)) {
	case 0: outstring = RED"\n"; break;
        case 1: outstring = HIR"\n"; break;
        case 2: outstring = GRN"\n"; break;
        case 3: outstring = HIG"\n"; break;
        case 4: outstring = YEL"\n"; break;
        case 5: outstring = HIY"\n"; break;
        case 6: outstring = BLU"\n"; break;
        case 7: outstring = HIB"\n"; break;
        case 8: outstring = HIM"\n"; break;
        case 9: outstring = HIC"\n"; break;
	}
	if(num>99999999) num =99999999;
	if(num >= 10000000) 
	{
	out = num/10000000;
	out8 = explode(c_num[out],"B");
	num = num%10000000;
	}
	else
	if(orinum > num)	
	out8 = explode(c_num[0],"B");
	else
	out8 = explode(output[0],"B");

        if(num >= 1000000) 
        {
        out = num/1000000;
        out7 = explode(c_num[out],"B");
        num = num%1000000;
        }
        else
        if(orinum > num)
        out7 = explode(c_num[0],"B");
        else
        out7 = explode(output[0],"B");


        if(num >= 100000) 
        {
        out = num/100000;
        out6= explode(c_num[out],"B");
        num = num%100000;
        }
        else
        if(orinum > num)
        out6 = explode(c_num[0],"B");
        else
        out6 = explode(output[0],"B");

        if(num >= 10000) 
        {
        out = num/10000;
        out5 = explode(c_num[out],"B");
        num = num%10000;
        }
        else
        if(orinum > num)
        out5 = explode(c_num[0],"B");
        else
        out5 = explode(output[0],"B");


        if(num >= 1000) 
        {
        out = num/1000;
        out4 = explode(c_num[out],"B");
        num = num%1000;
        }
        else
        if(orinum > num)
        out4 = explode(c_num[0],"B");
        else
        out4 = explode(output[0],"B");

        if(num >= 100) 
        {
        out = num/100;
        out3 = explode(c_num[out],"B");
        num = num%100;
        }
        else
        if(orinum > num)
        out3 = explode(c_num[0],"B");
        else
        out3 = explode(output[0],"B");


        if(num >= 10) 
        {
        out = num/10;
        out2 = explode(c_num[out],"B");
        num = num%10;
        }
        else
        if(orinum > num)
        out2 = explode(c_num[0],"B");
        else
        out2 = explode(output[0],"B");

        out1 = explode(c_num[num],"B");

	for(out=0;out<sizeof(out8);out++)
		outstring += addcolor(out8[out])+"  "+addcolor(out7[out])+"  "+
				addcolor(out6[out])+"  "+addcolor(out5[out])+"\n";
	outstring += "\n";
        for(out=0;out<sizeof(out4);out++)
                outstring += addcolor(out4[out])+"  "+addcolor(out3[out])+"  "+
			addcolor(out2[out])+"  "+addcolor(out1[out])+"\n";
return outstring+NOR;
}
string addcolor(string outstring)
{
        switch(random(10)) {
        case 0: outstring += RED; break;
        case 1: outstring += HIR; break;
        case 2: outstring += GRN; break;
        case 3: outstring += HIG; break;
        case 4: outstring += YEL; break;
        case 5: outstring += HIY; break;
        case 6: outstring += BLU; break;
        case 7: outstring += HIB; break;
        case 8: outstring += HIM; break;
        case 9: outstring += HIC; break;
        }

	return outstring;
}
