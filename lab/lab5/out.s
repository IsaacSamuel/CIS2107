
decode:     file format elf64-x86-64


Disassembly of section .init:

0000000000400488 <_init>:
  400488:	48 83 ec 08          	sub    $0x8,%rsp
  40048c:	48 8b 05 65 0b 20 00 	mov    0x200b65(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  400493:	48 85 c0             	test   %rax,%rax
  400496:	74 05                	je     40049d <_init+0x15>
  400498:	e8 53 00 00 00       	callq  4004f0 <__gmon_start__@plt>
  40049d:	48 83 c4 08          	add    $0x8,%rsp
  4004a1:	c3                   	retq   

Disassembly of section .plt:

00000000004004b0 <puts@plt-0x10>:
  4004b0:	ff 35 52 0b 20 00    	pushq  0x200b52(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4004b6:	ff 25 54 0b 20 00    	jmpq   *0x200b54(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4004bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004c0 <puts@plt>:
  4004c0:	ff 25 52 0b 20 00    	jmpq   *0x200b52(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4004c6:	68 00 00 00 00       	pushq  $0x0
  4004cb:	e9 e0 ff ff ff       	jmpq   4004b0 <_init+0x28>

00000000004004d0 <printf@plt>:
  4004d0:	ff 25 4a 0b 20 00    	jmpq   *0x200b4a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  4004d6:	68 01 00 00 00       	pushq  $0x1
  4004db:	e9 d0 ff ff ff       	jmpq   4004b0 <_init+0x28>

00000000004004e0 <__libc_start_main@plt>:
  4004e0:	ff 25 42 0b 20 00    	jmpq   *0x200b42(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  4004e6:	68 02 00 00 00       	pushq  $0x2
  4004eb:	e9 c0 ff ff ff       	jmpq   4004b0 <_init+0x28>

00000000004004f0 <__gmon_start__@plt>:
  4004f0:	ff 25 3a 0b 20 00    	jmpq   *0x200b3a(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4004f6:	68 03 00 00 00       	pushq  $0x3
  4004fb:	e9 b0 ff ff ff       	jmpq   4004b0 <_init+0x28>

0000000000400500 <atoi@plt>:
  400500:	ff 25 32 0b 20 00    	jmpq   *0x200b32(%rip)        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400506:	68 04 00 00 00       	pushq  $0x4
  40050b:	e9 a0 ff ff ff       	jmpq   4004b0 <_init+0x28>

0000000000400510 <exit@plt>:
  400510:	ff 25 2a 0b 20 00    	jmpq   *0x200b2a(%rip)        # 601040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400516:	68 05 00 00 00       	pushq  $0x5
  40051b:	e9 90 ff ff ff       	jmpq   4004b0 <_init+0x28>

Disassembly of section .text:

0000000000400520 <_start>:
  400520:	31 ed                	xor    %ebp,%ebp
  400522:	49 89 d1             	mov    %rdx,%r9
  400525:	5e                   	pop    %rsi
  400526:	48 89 e2             	mov    %rsp,%rdx
  400529:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40052d:	50                   	push   %rax
  40052e:	54                   	push   %rsp
  40052f:	49 c7 c0 f0 06 40 00 	mov    $0x4006f0,%r8
  400536:	48 c7 c1 80 06 40 00 	mov    $0x400680,%rcx
  40053d:	48 c7 c7 0d 06 40 00 	mov    $0x40060d,%rdi
  400544:	e8 97 ff ff ff       	callq  4004e0 <__libc_start_main@plt>
  400549:	f4                   	hlt    
  40054a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400550 <deregister_tm_clones>:
  400550:	b8 5f 10 60 00       	mov    $0x60105f,%eax
  400555:	55                   	push   %rbp
  400556:	48 2d 58 10 60 00    	sub    $0x601058,%rax
  40055c:	48 83 f8 0e          	cmp    $0xe,%rax
  400560:	48 89 e5             	mov    %rsp,%rbp
  400563:	77 02                	ja     400567 <deregister_tm_clones+0x17>
  400565:	5d                   	pop    %rbp
  400566:	c3                   	retq   
  400567:	b8 00 00 00 00       	mov    $0x0,%eax
  40056c:	48 85 c0             	test   %rax,%rax
  40056f:	74 f4                	je     400565 <deregister_tm_clones+0x15>
  400571:	5d                   	pop    %rbp
  400572:	bf 58 10 60 00       	mov    $0x601058,%edi
  400577:	ff e0                	jmpq   *%rax
  400579:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400580 <register_tm_clones>:
  400580:	b8 58 10 60 00       	mov    $0x601058,%eax
  400585:	55                   	push   %rbp
  400586:	48 2d 58 10 60 00    	sub    $0x601058,%rax
  40058c:	48 c1 f8 03          	sar    $0x3,%rax
  400590:	48 89 e5             	mov    %rsp,%rbp
  400593:	48 89 c2             	mov    %rax,%rdx
  400596:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40059a:	48 01 d0             	add    %rdx,%rax
  40059d:	48 d1 f8             	sar    %rax
  4005a0:	75 02                	jne    4005a4 <register_tm_clones+0x24>
  4005a2:	5d                   	pop    %rbp
  4005a3:	c3                   	retq   
  4005a4:	ba 00 00 00 00       	mov    $0x0,%edx
  4005a9:	48 85 d2             	test   %rdx,%rdx
  4005ac:	74 f4                	je     4005a2 <register_tm_clones+0x22>
  4005ae:	5d                   	pop    %rbp
  4005af:	48 89 c6             	mov    %rax,%rsi
  4005b2:	bf 58 10 60 00       	mov    $0x601058,%edi
  4005b7:	ff e2                	jmpq   *%rdx
  4005b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004005c0 <__do_global_dtors_aux>:
  4005c0:	80 3d 91 0a 20 00 00 	cmpb   $0x0,0x200a91(%rip)        # 601058 <__TMC_END__>
  4005c7:	75 11                	jne    4005da <__do_global_dtors_aux+0x1a>
  4005c9:	55                   	push   %rbp
  4005ca:	48 89 e5             	mov    %rsp,%rbp
  4005cd:	e8 7e ff ff ff       	callq  400550 <deregister_tm_clones>
  4005d2:	5d                   	pop    %rbp
  4005d3:	c6 05 7e 0a 20 00 01 	movb   $0x1,0x200a7e(%rip)        # 601058 <__TMC_END__>
  4005da:	f3 c3                	repz retq 
  4005dc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004005e0 <frame_dummy>:
  4005e0:	48 83 3d 38 08 20 00 	cmpq   $0x0,0x200838(%rip)        # 600e20 <__JCR_END__>
  4005e7:	00 
  4005e8:	74 1e                	je     400608 <frame_dummy+0x28>
  4005ea:	b8 00 00 00 00       	mov    $0x0,%eax
  4005ef:	48 85 c0             	test   %rax,%rax
  4005f2:	74 14                	je     400608 <frame_dummy+0x28>
  4005f4:	55                   	push   %rbp
  4005f5:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  4005fa:	48 89 e5             	mov    %rsp,%rbp
  4005fd:	ff d0                	callq  *%rax
  4005ff:	5d                   	pop    %rbp
  400600:	e9 7b ff ff ff       	jmpq   400580 <register_tm_clones>
  400605:	0f 1f 00             	nopl   (%rax)
  400608:	e9 73 ff ff ff       	jmpq   400580 <register_tm_clones>

000000000040060d <main>:
  40060d:	55                   	push   %rbp
  40060e:	48 89 e5             	mov    %rsp,%rbp
  400611:	48 83 ec 20          	sub    $0x20,%rsp
  400615:	89 7d ec             	mov    %edi,-0x14(%rbp)
  400618:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  40061c:	c7 45 fc b1 68 de 3a 	movl   $0x3ade68b1,-0x4(%rbp)
  400623:	83 7d ec 01          	cmpl   $0x1,-0x14(%rbp)
  400627:	7f 19                	jg     400642 <main+0x35>
  400629:	bf 08 07 40 00       	mov    $0x400708,%edi
  40062e:	b8 00 00 00 00       	mov    $0x0,%eax
  400633:	e8 98 fe ff ff       	callq  4004d0 <printf@plt>
  400638:	bf 01 00 00 00       	mov    $0x1,%edi
  40063d:	e8 ce fe ff ff       	callq  400510 <exit@plt>
  400642:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  400646:	48 83 c0 08          	add    $0x8,%rax
  40064a:	48 8b 00             	mov    (%rax),%rax
  40064d:	48 89 c7             	mov    %rax,%rdi
  400650:	e8 ab fe ff ff       	callq  400500 <atoi@plt>
  400655:	3b 45 fc             	cmp    -0x4(%rbp),%eax
  400658:	74 0c                	je     400666 <main+0x59>
  40065a:	bf 60 07 40 00       	mov    $0x400760,%edi
  40065f:	e8 5c fe ff ff       	callq  4004c0 <puts@plt>
  400664:	eb 0a                	jmp    400670 <main+0x63>
  400666:	bf 90 07 40 00       	mov    $0x400790,%edi
  40066b:	e8 50 fe ff ff       	callq  4004c0 <puts@plt>
  400670:	c9                   	leaveq 
  400671:	c3                   	retq   
  400672:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400679:	00 00 00 
  40067c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400680 <__libc_csu_init>:
  400680:	41 57                	push   %r15
  400682:	41 89 ff             	mov    %edi,%r15d
  400685:	41 56                	push   %r14
  400687:	49 89 f6             	mov    %rsi,%r14
  40068a:	41 55                	push   %r13
  40068c:	49 89 d5             	mov    %rdx,%r13
  40068f:	41 54                	push   %r12
  400691:	4c 8d 25 78 07 20 00 	lea    0x200778(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400698:	55                   	push   %rbp
  400699:	48 8d 2d 78 07 20 00 	lea    0x200778(%rip),%rbp        # 600e18 <__init_array_end>
  4006a0:	53                   	push   %rbx
  4006a1:	4c 29 e5             	sub    %r12,%rbp
  4006a4:	31 db                	xor    %ebx,%ebx
  4006a6:	48 c1 fd 03          	sar    $0x3,%rbp
  4006aa:	48 83 ec 08          	sub    $0x8,%rsp
  4006ae:	e8 d5 fd ff ff       	callq  400488 <_init>
  4006b3:	48 85 ed             	test   %rbp,%rbp
  4006b6:	74 1e                	je     4006d6 <__libc_csu_init+0x56>
  4006b8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4006bf:	00 
  4006c0:	4c 89 ea             	mov    %r13,%rdx
  4006c3:	4c 89 f6             	mov    %r14,%rsi
  4006c6:	44 89 ff             	mov    %r15d,%edi
  4006c9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4006cd:	48 83 c3 01          	add    $0x1,%rbx
  4006d1:	48 39 eb             	cmp    %rbp,%rbx
  4006d4:	75 ea                	jne    4006c0 <__libc_csu_init+0x40>
  4006d6:	48 83 c4 08          	add    $0x8,%rsp
  4006da:	5b                   	pop    %rbx
  4006db:	5d                   	pop    %rbp
  4006dc:	41 5c                	pop    %r12
  4006de:	41 5d                	pop    %r13
  4006e0:	41 5e                	pop    %r14
  4006e2:	41 5f                	pop    %r15
  4006e4:	c3                   	retq   
  4006e5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4006ec:	00 00 00 00 

00000000004006f0 <__libc_csu_fini>:
  4006f0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004006f4 <_fini>:
  4006f4:	48 83 ec 08          	sub    $0x8,%rsp
  4006f8:	48 83 c4 08          	add    $0x8,%rsp
  4006fc:	c3                   	retq   
