while (temp_node){ 
	
	cnt2 = 0;

	for(i = 0; i < cnt1; i++){

		printf("%d ", temp_node->data);

		/*Enqueue left child */

		if (temp_node->left){

			enQueue(queue, &rear, temp_node->left);

			cnt2++;

		}

		/*Enqueue right child */

		if (temp_node->right){

			cnt2++;

			enQueue(queue, &rear, temp_node->right);

		}

		/*Dequeue node and make it temp_node*/

		temp_node = deQueue(queue, &front);

	}

	cnt1 = cnt2;

	printf("\n");

}