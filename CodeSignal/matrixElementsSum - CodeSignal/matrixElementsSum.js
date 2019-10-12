/*************************************/
/* matrixElementsSum - CodeSignal    */
/* Created by Alexandre Hiroyuki     */
/* October 12, 2019                 */
/*************************************/

function matrixElementsSum(matrix) {
    let sum = 0
    for(i = 0; i < matrix[0].length; i++){
        for(j = 0; j < matrix.length; j++){
            if(matrix[j][i] !== 0){
                sum += matrix[j][i]
            }
            else{
                break;
            }
        }
    }
    
    return sum
}
