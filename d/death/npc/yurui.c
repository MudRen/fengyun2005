#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("玉蕊", ({ "yurui"}) );
    	set("gender", "女性");
    	set("age", 21);
    	set("per", 60);
    	set("long", "玉蕊生前是个歌姬，如花似玉，和葛生相恋至深，但葛生很穷，一直娶
不起玉蕊。后来葛生进京赶考，一去数载，玉蕊苦思成疾，年轻轻地竟
撒手而去。阎罗王念她生前为善，让她下辈子投于富豪之家，但玉蕊生
怕误了葛生的约定，不愿喝下那碗醧忘之汤，终日徘徊在奈何桥边等待。"YEL"
(ask yurui about soup)\n"NOR);
    	set("attitude", "peaceful");
    	set("title", WHT"【三世轮回】"NOR);
    	set("inquiry",	([
    		"soup":	"喝了孟婆的醧忘之汤，熬过了伤逝的时辰，就能够走过"YEL"奈何桥"CYN"了。\n",
    		"*":	"action玉蕊指指"WHT"迷雾"CYN"缭绕的桥那一端，叹了口气。\n",
    	]));
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	CYN"
玉蕊幽幽地说道：连就连，
		你我相约定百年。
		谁若九十七岁死，
		奈何桥上等三年。\n"NOR,        	
    	}) );
    	
    	set("combat_exp", 2000);
    	set("no_arrest", 1);
    	
    	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();
}

int is_ghost(){	return 1;}
	