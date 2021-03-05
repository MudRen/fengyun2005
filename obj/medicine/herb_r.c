/*	Herb heal by silencer@fy4.

compared it with normal healing pills
1. 5 silver 狗皮膏药 					20 sen
2. 20 silver 云南白药，大风丸，虎骨丸 			100kee/50sen/50gin
3. 60 silver 熊掌/人参/鹿茸  				300kee/200gin/200sen
4. 100 silver	七色雨虹花/三叶凤尾草/雪芝  		1500kee/1000sen/1000gin
5. 200 silver	九花玉露丸/白云熊胆丸/翠袖护心丹	5000kee/2500sen/2500gin

还魂草

all can be collected by knight player.

L 100 herb, can be bought
type 1: herb_a: "龙胆草","谷精草","金钱草","地耳草","灯心草", 	Level 100,  base_value 0.3-0.8g,    effect 500-2500 kee
type 2: herb_b: " "木香","青木香","檀香",			Level 100, base_value 0.5-0.7g      effect 500-1000-2000 sen/gin

L Level 150 herb random_drop 
type 1: herb_c: "冬虫夏草","紫河车","七叶龙爪花",  random(3) drop, knight 3000, 3500, 4000 kee
type 5: herb_d: "白花蛇草","七心海棠","罂粟叶",    poison self-made weapon..... 
type 4  herb_e: "金银花"	depoison

L 200 herb
type 3: herb_f: "灵芝","紫藤叶"	random drop    4000/2000/2000 cure poison, heal both value.

So the parameters are
Level: requirement for herb level
field:  kee/gin(sen)/full/depoison/poison
effect: amount that it heals

*/

inherit MEDICINE;
#include <ansi.h>

void create(){
	set_name(BLU"还魂草"NOR,({"huanhun", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一种奇异的药草，据说有起死回生之效。\n");
	    set("unit","簇");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("base_value",300000);
	    set("revive",1);	
	    set("material","herb");
	    set("type","revive");
	    set("volumn",1);
	}
	set_amount(1);
}
